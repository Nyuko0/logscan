#include <getopt.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "level.h"

#include "cli.h"

static struct option options[] = { { "file", required_argument, NULL, 'f'},
                                   { "level", required_argument, NULL, 'l'},
                                   { "contains", required_argument, NULL, 'c'},
                                   { "stats", no_argument, NULL, 's'},
                                   { "help", no_argument, NULL, 'h'}};

struct config *config_init(int argc, char **argv) {
    struct config *config = calloc(1, sizeof(struct config));
    if (!config) {
        return NULL;
    }
    config->level = FATAL;
    char ch;
    enum level_t level;
    while((ch = getopt_long(argc, argv, "f:l:c:sh", options, NULL)) != -1) {
        switch (ch) {
            case 'f':
                config->filepath = optarg;
                break;
            case 'l':
                if ((level = set_level(optarg)) == UNDEFINED) {
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
        }
    }
    return config;

stop:
    free(config);
    return NULL;
}
