 	dir->nr = dst - dir->entries;
 
 	for (i = 0; i < specs; i++) {
-		struct stat st;
-		const char *match;
-		if (seen[i])
-			continue;
-
-		match = pathspec[i];
-		if (!match[0])
-			continue;
-
-		/* Existing file? We must have ignored it */
-		if (!lstat(match, &st)) {
-			struct dir_entry *ent;
-
-			ent = dir_add_name(dir, match, strlen(match));
-			ent->ignored = 1;
-			if (S_ISDIR(st.st_mode))
-				ent->ignored_dir = 1;
-			continue;
-		}
-		die("pathspec '%s' did not match any files", match);
+		if (!seen[i] && !file_exists(pathspec[i]))
+			die("pathspec '%s' did not match any files",
+					pathspec[i]);
 	}
 }
 
-static void fill_directory(struct dir_struct *dir, const char **pathspec)
+static void fill_directory(struct dir_struct *dir, const char **pathspec,
+		int ignored_too)
 {
 	const char *path, *base;
 	int baselen;
 
 	/* Set up the default git porcelain excludes */
 	memset(dir, 0, sizeof(*dir));
-	dir->exclude_per_dir = ".gitignore";
-	path = git_path("info/exclude");
-	if (!access(path, R_OK))
-		add_excludes_from_file(dir, path);
-	if (!access(excludes_file, R_OK))
-		add_excludes_from_file(dir, excludes_file);
+	if (!ignored_too) {
+		dir->collect_ignored = 1;
+		dir->exclude_per_dir = ".gitignore";
+		path = git_path("info/exclude");
+		if (!access(path, R_OK))
+			add_excludes_from_file(dir, path);
+		if (!access(excludes_file, R_OK))
+			add_excludes_from_file(dir, excludes_file);
+	}
 
 	/*
 	 * Calculate common prefix for the pathspec, and
