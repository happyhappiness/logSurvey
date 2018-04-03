 	va_end(params);
 }
 
-void usage(const char *err)
+void NORETURN usage(const char *err)
 {
 	usagef("%s", err);
 }
 
-void die(const char *err, ...)
+void NORETURN die(const char *err, ...)
 {
 	va_list params;
 
