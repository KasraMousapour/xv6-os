#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "costum_logger.h"



// Logger implementation, which prints the message with the corresponding log level.
void logger(const char *message, LogLevel level_log) {
    switch (level_log) {
        case INFO:
            printf("[INFO]: %s\n", message);
            break;
        case WARN:
            printf("[WARN]: %s\n", message);
            break;
        case ERROR:
            printf("[ERROR]: %s\n", message);
            break;
        default:
            printf("[UNKNOWN]: %s\n", message);
            break;
    }
}

