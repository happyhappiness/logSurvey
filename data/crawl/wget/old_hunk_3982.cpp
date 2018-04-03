   them here.  */
enum log_options { LOG_VERBOSE, LOG_NOTQUIET, LOG_NONVERBOSE, LOG_ALWAYS };

void logprintf PARAMS ((enum log_options, const char *, ...))
     GCC_FORMAT_ATTR (2, 3);
void debug_logprintf PARAMS ((const char *, ...)) GCC_FORMAT_ATTR (1, 2);
void logputs PARAMS ((enum log_options, const char *));

/* Defined in `utils.c', but used literally everywhere.  */
