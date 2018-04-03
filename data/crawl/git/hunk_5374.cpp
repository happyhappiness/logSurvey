  */
 #include "git-compat-util.h"
 
-static void report(const char *prefix, const char *err, va_list params)
+void vreportf(const char *prefix, const char *err, va_list params)
 {
 	char msg[4096];
 	vsnprintf(msg, sizeof(msg), err, params);
