#include "level.h"

#include <string.h>

enum level_t set_level(char *str)
{
    if (!strcmp("TRACE", str))
    {
        return TRACE;
    }
    if (!strcmp("DEBUG", str))
    {
        return DEBUG;
    }
    if (!strcmp("INFO", str))
    {
        return INFO;
    }
    if (!strcmp("WARN", str))
    {
        return WARN;
    }
    if (!strcmp("ERROR", str))
    {
        return ERROR;
    }
    if (!strcmp("FATAL", str))
    {
        return FATAL;
    }
    return UNDEFINED;
}
