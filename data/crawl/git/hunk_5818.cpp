 	/* Finally, get the commit message */
 	strbuf_reset(&sb);
 	if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
+		int saved_errno = errno;
 		rollback_index_files();
-		die("could not read commit message");
+		die("could not read commit message: %s", strerror(saved_errno));
 	}
 
 	/* Truncate the message just before the diff, if any. */
