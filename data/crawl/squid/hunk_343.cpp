 
 #define debug(X...) \
                      if (debug_enabled) { \
-                         fprintf(stderr, "%s(%d): pid=%ld :", __FILE__, __LINE__, (long)getpid() ); \
+                         fprintf(stderr, "%s(%d): pid=%ld :", __FILE__, __LINE__, static_cast<long>(getpid())); \
                          fprintf(stderr,X); \
                      } else (void)0
 
+#define ndebug(content) ndebug_(__FILE__, __LINE__, content)
+#define ndebug_(file, line, content) if (debug_enabled) { \
+    std::cerr << file << '(' << line << ')' << ": pid=" << getpid() << ':' \
+        << content << std::endl; \
+    } else (void)0
+
 #else /* __GNUC__ */
 
 /* non-GCC compilers can't do the above macro define yet. */
