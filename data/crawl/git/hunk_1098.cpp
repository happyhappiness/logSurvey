 	    const char *template_dir, unsigned int flags)
 {
 	int reinit;
+	int exist_ok = flags & INIT_DB_EXIST_OK;
 
-	set_git_dir_init(git_dir, real_git_dir, flags & INIT_DB_EXIST_OK);
+	if (real_git_dir) {
+		struct stat st;
 
+		if (!exist_ok && !stat(git_dir, &st))
+			die(_("%s already exists"), git_dir);
+
+		if (!exist_ok && !stat(real_git_dir, &st))
+			die(_("%s already exists"), real_git_dir);
+
+		/*
+		 * make sure symlinks are resolved because we'll be
+		 * moving the target repo later on in separate_git_dir()
+		 */
+		git_link = xstrdup(real_path(git_dir));
+		set_git_dir(real_path(real_git_dir));
+	}
+	else {
+		set_git_dir(real_path(git_dir));
+		git_link = NULL;
+	}
+	startup_info->have_repository = 1;
 	git_dir = get_git_dir();
 
 	if (git_link)