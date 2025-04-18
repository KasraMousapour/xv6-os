#ifndef LOGGER_CUSTOM_H
#define LOGGER_CUSTOM_H

// Define logging levels using an enum for better readability.
typedef enum {
    INFO = 0,    // Info messages
    ERROR = 1,   // Error messages (if level equals 1, consider as ERROR)
    WARN = 2     // Warning messages
} LogLevel;

// Logger function prototype.
// It receives a message (const char *) and a log level (LogLevel, passed as an int).
void logger(const char *message, LogLevel level_log);

#endif  // LOGGER_CUSTOM_H

