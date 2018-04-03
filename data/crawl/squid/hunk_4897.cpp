         (((ch) == DIR_SEPARATOR) || ((ch) == DIR_SEPARATOR_2))
 #endif /* DIR_SEPARATOR_2 */
 
+#ifndef PATH_SEPARATOR_2
+# define IS_PATH_SEPARATOR(ch) ((ch) == PATH_SEPARATOR)
+#else /* PATH_SEPARATOR_2 */
+# define IS_PATH_SEPARATOR(ch) ((ch) == PATH_SEPARATOR_2)
+#endif /* PATH_SEPARATOR_2 */
+
 #define XMALLOC(type, num)      ((type *) xmalloc ((num) * sizeof(type)))
 #define XFREE(stale) do { \
   if (stale) { free ((void *) stale); stale = 0; } \
 } while (0)
 
+/* -DDEBUG is fairly common in CFLAGS.  */
+#undef DEBUG
+#if defined DEBUGWRAPPER
+# define DEBUG(format, ...) fprintf(stderr, format, __VA_ARGS__)
+#else
+# define DEBUG(format, ...)
+#endif
+
 const char *program_name = NULL;
 
 void * xmalloc (size_t num);
 char * xstrdup (const char *string);
-char * basename (const char *name);
-char * fnqualify(const char *path);
+const char * base_name (const char *name);
+char * find_executable(const char *wrapper);
+int    check_executable(const char *path);
 char * strendzap(char *str, const char *pat);
 void lt_fatal (const char *message, ...);
 
