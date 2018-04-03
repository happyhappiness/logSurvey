 
 	if (active_cache_changed &&
 	    (write_cache(index_fd, active_cache, active_nr) ||
-	     close(index_fd) || commit_locked_index(lock)))
+	     commit_locked_index(lock)))
 			die ("unable to write %s", get_index_file());
 
 	return clean ? 0: 1;
