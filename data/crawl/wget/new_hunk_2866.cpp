
enum log_options { LOG_VERBOSE, LOG_NOTQUIET, LOG_NONVERBOSE, LOG_ALWAYS };

void logprintf (enum log_options, const char *, ...)
     GCC_FORMAT_ATTR (2, 3);
void debug_logprintf (const char *, ...) GCC_FORMAT_ATTR (1, 2);
void logputs (enum log_options, const char *);
void logflush (void);
void log_set_flush (int);
int log_set_save_context (int);

void log_init (const char *, int);
void log_close (void);
void log_cleanup (void);
void log_request_redirect_output (const char *);

const char *escnonprint (const char *);
const char *escnonprint_uri (const char *);

#endif /* LOG_H */
