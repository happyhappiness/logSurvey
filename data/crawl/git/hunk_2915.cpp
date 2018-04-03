 	if (write_shallow_commits_1(&sb, 0, NULL, SEEN_ONLY)) {
 		if (write_in_full(fd, sb.buf, sb.len) != sb.len)
 			die_errno("failed to write to %s",
-				  shallow_lock.filename.buf);
+				  get_lock_file_path(&shallow_lock));
 		commit_lock_file(&shallow_lock);
 	} else {
 		unlink(git_path("shallow"));