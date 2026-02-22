#ifndef LOG_ENTRY_H
#define LOG_ENTRY_H

#include "level.h"
#include <time.h>

struct log_entry {
    char *raw_line;
    enum level_t level;
    char *message;
    time_t timestamp;
};

#endif /* LOG_ENTRY_H */
