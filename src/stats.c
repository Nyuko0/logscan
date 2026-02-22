#include "stats.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "log_entry.h"

static struct log_stats* stats = NULL;

bool init_stats(void) {
    stats = calloc(1, sizeof(struct log_stats));
    if (!stats) {
        return false;
    }
    return true;
}

void destroy_stats(void) {
    free(stats);
}

void update_stats(struct log_entry *entry) {
    if (!stats) {
        return;
    }

    if (!entry) {
        stats->wrong_lines += 1;
        return;
    }

    stats->total_lines += 1;
    stats->level_count[entry->level] += 1;
}
