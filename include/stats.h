#ifndef STATS_H
#define STATS_H

#include <stddef.h>
#include <stdbool.h>
#include "log_entry.h"

struct log_stats {
    size_t total_lines;
    size_t wrong_lines;
    size_t level_count[6];
};

bool init_stats(void);
void update_stats(struct log_entry *entry);
void destroy_stats(void);

#endif /* STATS_H */
