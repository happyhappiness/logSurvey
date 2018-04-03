 	if (!(flags & INIT_DB_QUIET)) {
 		const char *git_dir = get_git_dir();
 		int len = strlen(git_dir);
-		printf("%s%s Git repository in %s%s\n",
-		       reinit ? "Reinitialized existing" : "Initialized empty",
-		       shared_repository ? " shared" : "",
+
+		/*
+		 * TRANSLATORS: The first '%s' is either "Reinitialized
+		 * existing" or "Initialized empty", the second " shared" or
+		 * "", and the last '%s%s' is the verbatim directory name.
+		 */
+		printf(_("%s%s Git repository in %s%s\n"),
+		       reinit ? _("Reinitialized existing") : _("Initialized empty"),
+		       shared_repository ? _(" shared") : "",
 		       git_dir, len && git_dir[len-1] != '/' ? "/" : "");
 	}
 
