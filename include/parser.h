#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

char *read_next_entry(FILE* stream);
struct log_entry *parse_log_entry(char *log_str);

#endif /* PARSER_H */
