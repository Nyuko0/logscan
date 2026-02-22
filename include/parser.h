#ifndef PARSER_H
#define PARSER_H

#include "level.h"
#include <time.h>
#include <stdio.h>

struct log_entry {
    enum level_t level;
    char *message;
    time_t timestamp;
};

char *read_next_entry(FILE* stream);
struct log_entry *parse_log_entry(char *log_str);

#endif /* PARSER_H */
