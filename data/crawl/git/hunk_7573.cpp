 
 	if (0 <= newfd &&
 	    (write_cache(newfd, active_cache, active_nr) ||
-	     close(newfd) || commit_locked_index(&lock_file)))
+	     commit_locked_index(&lock_file)))
 		die("Unable to write new index file");
 	return 0;
 }