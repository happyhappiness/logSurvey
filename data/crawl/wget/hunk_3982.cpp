    them here.  */
 enum log_options { LOG_VERBOSE, LOG_NOTQUIET, LOG_NONVERBOSE, LOG_ALWAYS };
 
+#ifdef HAVE_STDARG_H
 void logprintf PARAMS ((enum log_options, const char *, ...))
      GCC_FORMAT_ATTR (2, 3);
 void debug_logprintf PARAMS ((const char *, ...)) GCC_FORMAT_ATTR (1, 2);
+#else  /* not HAVE_STDARG_H */
+void logprintf ();
+void debug_logprintf ();
+#endif /* not HAVE_STDARG_H */
 void logputs PARAMS ((enum log_options, const char *));
 
 /* Defined in `utils.c', but used literally everywhere.  */
