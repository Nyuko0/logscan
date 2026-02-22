#define _POSIX_C_SOURCE 200809L

#include "parser.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "level.h"
#include "log_entry.h"


char *read_next_entry(FILE* stream) {
    char *line = NULL;
    size_t len = 0;

    ssize_t read = getline(&line, &len, stream);
    if (read == -1) {
        free(line);
        return NULL;
    }

    return line;
}

static bool get_timestamp(char *str, time_t *res) {
    int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;

    if (sscanf(str, "%4d-%2d-%2d %2d:%2d:%2d", &year, &month, &day, &hour, &min, &sec) == 6) {
        struct tm breakdown = {0};
        breakdown.tm_year = year - 1900;
        breakdown.tm_mon = month - 1;
        breakdown.tm_mday = day;
        breakdown.tm_hour = hour;
        breakdown.tm_min = min;
        breakdown.tm_sec = sec;

        if ((*res = mktime(&breakdown)) == (time_t)-1) {
            return false;
        }

        return true;
    }
    return false;
}

static char *parse_timestamp(char *str, time_t *timestamp) {
    if (*str != '[') {
        return NULL;
    }

    char *head = ++str;
    while (str != NULL && *str != ']') {
        str++;
    }
    if (str == NULL) {
        return NULL;
    }
    char tmp = *str;
    *str = '\0';
    time_t res = 0;
    if (!get_timestamp(head, &res)) {
        return NULL;
    }
    *timestamp = res;
    *str = tmp;
    str++;
    return str;
}

static char *parse_level(char *str, enum level_t *level) {
    if (*str != '[') {
        return NULL;
    }

    char *head = ++str;
    while (*str != '\0' && *str != ']') {
        str++;
    }
    if (str == NULL) {
        return NULL;
    }
    char tmp = *str;
    *str = '\0';
    *level = set_level(head);
    *str = tmp;
    str++;
    return str;
}

struct log_entry *parse_log_entry(char *log_str) {
    struct log_entry *entry = malloc(sizeof(struct log_entry));
    if (!entry) {
        return NULL;
    }
    if (log_str == NULL || *log_str == '\0') {
        goto stop;
    }
    entry->raw_line = log_str;
    time_t timestamp;
    log_str = parse_timestamp(log_str, &timestamp);
    if (log_str == NULL || *log_str == '\0') {
        goto stop;
    }
    log_str++;
    enum level_t level;
    log_str = parse_level(log_str, &level);
    if (log_str == NULL || *log_str == '\0' || level == UNDEFINED) {
        goto stop;
    }
    log_str++;
    if (*log_str == '\0') {
        goto stop;
    }
    entry->timestamp = timestamp;
    entry->level = level;
    entry->message = strdup(log_str);
    return entry;

stop:
    free(entry);
    return NULL;
}
