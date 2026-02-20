#include "cli.h"
#include <stddef.h>
#include <stdio.h>

static void print_help(void) {
    printf(
            "logscan - Fast log file analyzer written in C\n"
            "\n"
            "Usage:\n"
            "  logscan -f <file> [OPTIONS]\n"
            "\n"
            "Description:\n"
            "  logscan reads a log file in streaming mode and applies filters,\n"
            "  statistics, and formatting without loading the entire file into memory.\n"
            "\n"
            "Required:\n"
            "  -f, --file <path>              Path to the log file to analyze\n"
            "\n"
            "Filtering Options:\n"
            "  -l, --level <LEVEL>            Show only logs matching LEVEL\n"
            "                                  (TRACE, DEBUG, INFO, WARN, ERROR, FATAL)\n"
            "\n"
            "      --min-level <LEVEL>        Show logs with severity >= LEVEL\n"
            "\n"
            "  -c, --contains <STRING>        Show logs containing substring\n"
            "\n"
            "      --from <TIMESTAMP>         Show logs after timestamp\n"
            "      --to <TIMESTAMP>           Show logs before timestamp\n"
            "\n"
            "                                  Timestamp format:\n"
            "                                  \"YYYY-MM-DD HH:MM:SS\"\n"
            "\n"
            "Output Options:\n"
            "  -s, --stats                    Display statistics only\n"
            "      --top <N>                  Show top N most frequent messages\n"
            "      --color                    Enable colored output\n"
            "\n"
            "Other Options:\n"
            "  -h, --help                     Show this help message\n"
            "      --version                  Show program version\n"
            "\n"
            "Examples:\n"
            "  logscan -f server.log\n"
            "  logscan -f server.log -l ERROR\n"
            "  logscan -f server.log --min-level WARN\n"
            "  logscan -f server.log -c \"database\" --color\n"
            "  logscan -f server.log --stats\n"
            "  logscan -f server.log --from \"2026-02-15 00:00:00\" --to \"2026-02-16 00:00:00\"\n"
            "\n"
            "Exit Status:\n"
            "  0   Success\n"
            "  1   Error (invalid arguments, file error, parsing failure)\n"
            );
}

int main(int argc, char** argv) {
    struct config *config = config_init(argc, argv);
    if (config == NULL) {
        return 1;
    }

    if (config->help) {
        print_help();
        return 0;
    }
}
