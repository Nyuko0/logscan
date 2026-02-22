#ifndef LEVEL_H
#define LEVEL_H

enum level_t {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL,
    UNDEFINED
};

enum level_t set_level(char *str);

#endif /* LEVEL_H */
