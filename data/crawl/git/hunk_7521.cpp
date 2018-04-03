 	execlp("info", "info", "gitman", page, NULL);
 }
 
+static void get_html_page_path(struct strbuf *page_path, const char *page)
+{
+	struct stat st;
+
+	/* Check that we have a git documentation directory. */
+	if (stat(GIT_HTML_PATH "/git.html", &st) || !S_ISREG(st.st_mode))
+		die("'%s': not a documentation directory.", GIT_HTML_PATH);
+
+	strbuf_init(page_path, 0);
+	strbuf_addf(page_path, GIT_HTML_PATH "/%s.html", page);
+}
+
 static void show_html_page(const char *git_cmd)
 {
 	const char *page = cmd_to_page(git_cmd);
-	execl_git_cmd("help--browse", page, NULL);
+	struct strbuf page_path; /* it leaks but we exec bellow */
+
+	get_html_page_path(&page_path, page);
+
+	execl_git_cmd("help--browse", page_path.buf, NULL);
 }
 
 void help_unknown_cmd(const char *cmd)