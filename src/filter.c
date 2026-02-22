#include "filter.h"

#include <stdbool.h>
#include <string.h>

#include "cli.h"

static bool check_level(struct config *config, struct log_entry *entry)
{
    return config->level >= entry->level;
}

static bool check_contains(struct config *config, struct log_entry *entry)
{
    return !config->contains || strstr(entry->message, config->contains);
}

bool check_filter(struct config *config, struct log_entry *entry)
{
    if (!check_contains(config, entry))
    {
        return false;
    }

    if (!check_level(config, entry))
    {
        return false;
    }

    return true;
}
