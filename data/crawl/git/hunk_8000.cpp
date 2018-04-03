 	return git_config_bool(var, value);
 }
 
-static int color_vprintf(const char *color, const char *fmt,
+static int color_vfprintf(FILE *fp, const char *color, const char *fmt,
 		va_list args, const char *trail)
 {
 	int r = 0;
 
 	if (*color)
-		r += printf("%s", color);
-	r += vprintf(fmt, args);
+		r += fprintf(fp, "%s", color);
+	r += vfprintf(fp, fmt, args);
 	if (*color)
-		r += printf("%s", COLOR_RESET);
+		r += fprintf(fp, "%s", COLOR_RESET);
 	if (trail)
-		r += printf("%s", trail);
+		r += fprintf(fp, "%s", trail);
 	return r;
 }
 
 
 
-int color_printf(const char *color, const char *fmt, ...)
+int color_fprintf(FILE *fp, const char *color, const char *fmt, ...)
 {
 	va_list args;
 	int r;
 	va_start(args, fmt);
-	r = color_vprintf(color, fmt, args, NULL);
+	r = color_vfprintf(fp, color, fmt, args, NULL);
 	va_end(args);
 	return r;
 }
 
-int color_printf_ln(const char *color, const char *fmt, ...)
+int color_fprintf_ln(FILE *fp, const char *color, const char *fmt, ...)
 {
 	va_list args;
 	int r;
 	va_start(args, fmt);
-	r = color_vprintf(color, fmt, args, "\n");
+	r = color_vfprintf(fp, color, fmt, args, "\n");
 	va_end(args);
 	return r;
 }
