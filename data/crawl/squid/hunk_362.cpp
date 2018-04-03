 
 #define debug(X...) \
                      if (debug_enabled) { \
-                         fprintf(stderr, "%s(%d): pid=%ld :", __FILE__, __LINE__, (long)getpid() ); \
+                         fprintf(stderr, "%s(%d): pid=%ld :", __FILE__, __LINE__, static_cast<long>(getpid())); \
                          fprintf(stderr,X); \
                      } else (void)0
 
