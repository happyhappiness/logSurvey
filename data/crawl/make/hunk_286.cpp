 #  define RECORD_SYNC_MUTEX(m) (void)(m)
 
 # endif
-#else /* !OUTPUT_SYNC */
-#define RECORD_SYNC_MUTEX(m) \
-   error (NILF, \
-         _("-O[TYPE] (--output-sync[=TYPE]) is not configured for this build."));
-#endif  /* OUTPUT_SYNC */
+#endif  /* !OUTPUT_SYNC */
 
 /* Structure describing a running or dead child process.  */
 
