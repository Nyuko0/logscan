#ifndef FILTER_H
#define FILTER_H

#include "log_entry.h"
#include "cli.h"
#include "stdbool.h"

bool check_filter(struct config *config, struct log_entry *entry);

#endif /* FILTER_H */
