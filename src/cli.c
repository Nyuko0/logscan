#include <getopt.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cli.h"

static struct option options[] = { { "file", required_argument, NULL, 'f'},
                                   { "level", required_argument, NULL, 'l'},
                                   { "contains", required_argument, NULL, 'c'},
                                   { "stats", no_argument, NULL, 's'},
                                   { "help", no_argument, NULL, 'h'}};

static enum level_t set_level(char *str) {
    if (!strcmp("TRACE", str)) {
        return TRACE;
    }
    if (!strcmp("DEBUG", str)) {
        return DEBUG;
    }
    if (!strcmp("INFO", str)) {
        return INFO;
    }
    if (!strcmp("WARN", str)) {
        return WARN;
    }
    if (!strcmp("ERROR", str)) {
        return ERROR;
    }
    if (!strcmp("FATAL", str)) {
        return FATAL;
    }
    return UNDEFINED;
}


struct config *config_init(int argc, char **argv) {
    struct config *config = calloc(0, sizeof(struct config));
    char ch;
    enum level_t level;
    while((ch = getopt_long(argc, argv, "f:l:c:sh", options, NULL)) != -1) {
        switch (ch) {
            case 'f':
                config->filepath = optarg;
                break;
            case 'l':
                if ((level = set_level(optarg) == UNDEFINED)) {
                    goto stop;
                }
                config->level = level;
                break;
            case 'c':
                config->contains = optarg;
                break;
            case 's':
                config->stats = true;
                break;
            case 'h':
                config->help = true;
                return config;
            default:
                goto stop;
                break;
        }
    }
    return config;

stop:
    free(config);
    return NULL;
}
