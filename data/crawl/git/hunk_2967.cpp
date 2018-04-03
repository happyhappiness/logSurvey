 		die(_("failed to read the index"));
 
 	if (am_in_progress(&state)) {
+		/*
+		 * Catch user error to feed us patches when there is a session
+		 * in progress:
+		 *
+		 * 1. mbox path(s) are provided on the command-line.
+		 * 2. stdin is not a tty: the user is trying to feed us a patch
+		 *    from standard input. This is somewhat unreliable -- stdin
+		 *    could be /dev/null for example and the caller did not
+		 *    intend to feed us a patch but wanted to continue
+		 *    unattended.
+		 */
+		if (argc || (resume == RESUME_FALSE && !isatty(0)))
+			die(_("previous rebase directory %s still exists but mbox given."),
+				state.dir);
+
 		if (resume == RESUME_FALSE)
 			resume = RESUME_APPLY;
 