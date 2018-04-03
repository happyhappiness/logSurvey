 	if (!strcmp(".", git_dir))
 		return 1;
 	if (!getcwd(cwd, sizeof(cwd)))
-		die_errno("cannot tell cwd");
+		die_errno(_("cannot tell cwd"));
 	if (!strcmp(git_dir, cwd))
 		return 1;
 	/*
