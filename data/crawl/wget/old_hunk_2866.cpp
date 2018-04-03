
enum log_options { LOG_VERBOSE, LOG_NOTQUIET, LOG_NONVERBOSE, LOG_ALWAYS };

#ifdef HAVE_STDARG_H
void logprintf PARAMS ((enum log_options, const char *, ...))
     GCC_FORMAT_ATTR (2, 3);
void debug_logprintf PARAMS ((const char *, ...)) GCC_FORMAT_ATTR (1, 2);
#else  /* not HAVE_STDARG_H */
void logprintf ();
void debug_logprintf ();
#endif /* not HAVE_STDARG_H */
void logputs PARAMS ((enum log_options, const char *));
void logflush PARAMS ((void));
void log_set_flush PARAMS ((int));
int log_set_save_context PARAMS ((int));

void log_init PARAMS ((const char *, int));
void log_close PARAMS ((void));
void log_cleanup PARAMS ((void));
void log_request_redirect_output PARAMS ((const char *));

const char *escnonprint PARAMS ((const char *));
const char *escnonprint_uri PARAMS ((const char *));

#endif /* LOG_H */
