 	const char *page = cmd_to_page(git_cmd);
 	setenv("INFOPATH", system_path(GIT_INFO_PATH), 1);
 	execlp("info", "info", "gitman", page, NULL);
+	die("no info viewer handled the request");
 }
 
 static void get_html_page_path(struct strbuf *page_path, const char *page)