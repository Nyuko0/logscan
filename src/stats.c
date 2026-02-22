#include "stats.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "log_entry.h"

static struct log_stats *stats = NULL;

bool init_stats(void)
{
    stats = calloc(1, sizeof(struct log_stats));
    if (!stats)
    {
        return false;
    }
    return true;
}

void destroy_stats(void)
{
    free(stats);
}

void update_stats(struct log_entry *entry)
{
    if (!stats)
    {
        return;
    }

    stats->total_lines++;
    if (!entry)
    {
        stats->wrong_lines++;
        return;
    }

    stats->level_count[entry->level]++;
}

void print_stats(void)
{
    printf("\n");
    printf("Total lines: %lu\n", stats->total_lines);
    printf("Parsed lines: %lu\n", stats->total_lines - stats->wrong_lines);
    printf("Malformed lines: %lu\n", stats->wrong_lines);
    printf("Levels:\n"
           "\tTRACE: %lu\n"
           "\tDEBUG: %lu\n"
           "\tINFO: %lu\n"
           "\tWARN: %lu\n"
           "\tERROR: %lu\n"
           "\tFATAL: %lu\n",
           stats->level_count[0], stats->level_count[1], stats->level_count[2],
           stats->level_count[3], stats->level_count[4], stats->level_count[5]);
}
