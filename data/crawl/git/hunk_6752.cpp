 	if (action == REVERT && !no_replay)
 		die("revert is incompatible with replay");
 
+	if (read_cache() < 0)
+		die("git %s: failed to read the index", me);
 	if (no_commit) {
 		/*
 		 * We do not intend to commit immediately.  We just want to
