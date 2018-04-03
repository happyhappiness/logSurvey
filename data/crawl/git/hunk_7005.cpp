 static void get_html_page_path(struct strbuf *page_path, const char *page)
 {
 	struct stat st;
+	const char *html_path = system_path(GIT_HTML_PATH);
 
 	/* Check that we have a git documentation directory. */
-	if (stat(GIT_HTML_PATH "/git.html", &st) || !S_ISREG(st.st_mode))
-		die("'%s': not a documentation directory.", GIT_HTML_PATH);
+	if (stat(mkpath("%s/git.html", html_path), &st)
+	    || !S_ISREG(st.st_mode))
+		die("'%s': not a documentation directory.", html_path);
 
 	strbuf_init(page_path, 0);
-	strbuf_addf(page_path, GIT_HTML_PATH "/%s.html", page);
+	strbuf_addf(page_path, "%s/%s.html", html_path, page);
 }
 
 static void show_html_page(const char *git_cmd)