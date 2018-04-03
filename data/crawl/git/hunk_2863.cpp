 #include "git-compat-util.h"
 #include "cache.h"
 
+static FILE *error_handle;
+
 void vreportf(const char *prefix, const char *err, va_list params)
 {
 	char msg[4096];
+	FILE *fh = error_handle ? error_handle : stderr;
 	vsnprintf(msg, sizeof(msg), err, params);
-	fprintf(stderr, "%s%s\n", prefix, msg);
-}
-
-void vwritef(int fd, const char *prefix, const char *err, va_list params)
-{
-	char msg[4096];
-	int len = vsnprintf(msg, sizeof(msg), err, params);
-	if (len > sizeof(msg))
-		len = sizeof(msg);
-
-	write_in_full(fd, prefix, strlen(prefix));
-	write_in_full(fd, msg, len);
-	write_in_full(fd, "\n", 1);
+	fprintf(fh, "%s%s\n", prefix, msg);
 }
 
 static NORETURN void usage_builtin(const char *err, va_list params)
