 
 int plugin_dispatch_notification (const notification_t *notif);
 
-void plugin_log (int level, const char *format, ...);
+void plugin_log (int level, const char *format, ...)
+	__attribute__ ((format(printf,2,3)));
+
 #define ERROR(...)   plugin_log (LOG_ERR,     __VA_ARGS__)
 #define WARNING(...) plugin_log (LOG_WARNING, __VA_ARGS__)
 #define NOTICE(...)  plugin_log (LOG_NOTICE,  __VA_ARGS__)