 	va_end(params);
 }
 
+void die_errno(const char *fmt, ...)
+{
+	va_list params;
+	char fmt_with_err[1024];
+
+	snprintf(fmt_with_err, sizeof(fmt_with_err), "%s: %s", fmt, strerror(errno));
+
+	va_start(params, fmt);
+	die_routine(fmt_with_err, params);
+	va_end(params);
+}
+
 int error(const char *err, ...)
 {
 	va_list params;