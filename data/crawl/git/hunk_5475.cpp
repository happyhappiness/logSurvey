 
 	git_config(git_rerere_gc_config, NULL);
 	dir = opendir(git_path("rr-cache"));
+	if (!dir)
+		die_errno("unable to open rr-cache directory");
 	while ((e = readdir(dir))) {
 		if (is_dot_or_dotdot(e->d_name))
 			continue;