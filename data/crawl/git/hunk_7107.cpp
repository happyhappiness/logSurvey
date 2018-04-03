 	else
 		die("Invalid cleanup mode %s", cleanup_arg);
 
+	if (!untracked_files_arg)
+		; /* default already initialized */
+	else if (!strcmp(untracked_files_arg, "normal"))
+		show_untracked_files = SHOW_NORMAL_UNTRACKED_FILES;
+	else if (!strcmp(untracked_files_arg, "all"))
+		show_untracked_files = SHOW_ALL_UNTRACKED_FILES;
+	else
+		die("Invalid untracked files mode '%s'", untracked_files_arg);
+
 	if (all && argc > 0)
 		die("Paths with -a does not make sense.");
 	else if (interactive && argc > 0)
