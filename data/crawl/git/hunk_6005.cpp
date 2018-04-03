 extern NORETURN void usage_with_options(const char * const *usagestr,
                                         const struct option *options);
 
+extern NORETURN void usage_msg_opt(const char *msg,
+				   const char * const *usagestr,
+				   const struct option *options);
+
 /*----- incremental advanced APIs -----*/
 
 enum {