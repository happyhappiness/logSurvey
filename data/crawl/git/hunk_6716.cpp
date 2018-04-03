 static void show_line(struct grep_opt *opt, const char *bol, const char *eol,
 		      const char *name, unsigned lno, char sign)
 {
+	if (opt->null_following_name)
+		sign = '\0';
 	if (opt->pathname)
 		printf("%s%c", name, sign);
 	if (opt->linenum)
 		printf("%d%c", lno, sign);
 	printf("%.*s\n", (int)(eol-bol), bol);
 }
 
+static void show_name(struct grep_opt *opt, const char *name)
+{
+	printf("%s%c", name, opt->null_following_name ? '\0' : '\n');
+}
+
 static int fixmatch(const char *pattern, char *line, regmatch_t *match)
 {
 	char *hit = strstr(line, pattern);
