 	return git_default_config(var, value, cb);
 }
 
+void color_print_strbuf(FILE *fp, const char *color, const struct strbuf *sb)
+{
+	if (*color)
+		fprintf(fp, "%s", color);
+	fprintf(fp, "%s", sb->buf);
+	if (*color)
+		fprintf(fp, "%s", GIT_COLOR_RESET);
+}
+
 static int color_vfprintf(FILE *fp, const char *color, const char *fmt,
 		va_list args, const char *trail)
 {
