 #define WARNING(...) plugin_log (LOG_WARNING, __VA_ARGS__)
 #define NOTICE(...)  plugin_log (LOG_NOTICE,  __VA_ARGS__)
 #define INFO(...)    plugin_log (LOG_INFO,    __VA_ARGS__)
-#define DEBUG(...)   plugin_log (LOG_DEBUG,   __VA_ARGS__)
+#if COLLECT_DEBUG
+# define DEBUG(...)  plugin_log (LOG_DEBUG,   __VA_ARGS__)
+#else /* COLLECT_DEBUG */
+# define DEBUG(...)  /* noop */
+#endif /* ! COLLECT_DEBUG */
 
 /* TODO: Move plugin_{complain,relief} into `utils_complain.[ch]'. -octo */
 void plugin_complain (int level, complain_t *c, const char *format, ...);