#ifndef CLI_H
#define CLI_H

#include <stdbool.h>
#include "level.h"

struct config {
    char* filepath;
    char* contains;
    enum level_t level;
    bool stats;
    bool help;
};

struct config *config_init(int argc, char **argv);
#endif /* CLI_H */
