 	return (e < 3 * x) ? n : n - 1;
 }
 
+void print_commit_list(struct commit_list *list,
+		       const char *format_cur,
+		       const char *format_last)
+{
+	for ( ; list; list = list->next) {
+		const char *format = list->next ? format_cur : format_last;
+		printf(format, sha1_to_hex(list->item->object.sha1));
+	}
+}
+
 static void show_tried_revs(struct commit_list *tried, int stringed)
 {
 	printf("bisect_tried='");
-	for (;tried; tried = tried->next) {
-		char *format = tried->next ? "%s|" : "%s";
-		printf(format, sha1_to_hex(tried->item->object.sha1));
-	}
+	print_commit_list(tried, "%s|", "%s");
 	printf(stringed ? "' &&\n" : "'\n");
 }
 
+static void print_var_str(const char *var, const char *val, int stringed)
+{
+	printf("%s='%s'%s\n", var, val, stringed ? " &&" : "");
+}
+
+static void print_var_int(const char *var, int val, int stringed)
+{
+	printf("%s=%d%s\n", var, val, stringed ? " &&" : "");
+}
+
 int show_bisect_vars(struct rev_list_info *info, int reaches, int all)
 {
-	int cnt, flags = info->bisect_show_flags;
-	char hex[41] = "", *format;
+	int cnt, stringed, flags = info->bisect_show_flags;
+	char hex[41] = "";
 	struct commit_list *tried;
 	struct rev_info *revs = info->revs;
 
