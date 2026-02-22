#ifndef LEVEL_H
#define LEVEL_H

enum level_t {
    TRACE = 0,
    DEBUG = 1,
    INFO = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5,
    UNDEFINED
};

enum level_t set_level(char *str);

#endif /* LEVEL_H */
