void debug_logprintf (const char *, ...) GCC_FORMAT_ATTR (1, 2);
void logputs (enum log_options, const char *);
void logflush (void);
void log_set_flush (bool);
bool log_set_save_context (bool);

void log_init (const char *, bool);
void log_close (void);
void log_cleanup (void);
void log_request_redirect_output (const char *);
