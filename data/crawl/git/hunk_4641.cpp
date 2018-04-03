 		usage(builtin_diff_usage);
 
 	if (lstat(path, &st))
-		die_errno("failed to stat '%s'", path);
+		die_errno(_("failed to stat '%s'"), path);
 	if (!(S_ISREG(st.st_mode) || S_ISLNK(st.st_mode)))
-		die("'%s': not a regular file or symlink", path);
+		die(_("'%s': not a regular file or symlink"), path);
 
 	diff_set_mnemonic_prefix(&revs->diffopt, "o/", "w/");
 
