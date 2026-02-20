#ifndef CLI_H
#define CLI_H

#include <stdbool.h>

enum level_t {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL,
    UNDEFINED
};

struct config {
    char* filepath;
    char* contains;
    enum level_t level;
    bool stats;
    bool help;
};

struct config *config_init(int argc, char **argv);
#endif /* CLI_H */
