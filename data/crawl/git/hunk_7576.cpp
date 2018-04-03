 	add_remove_files(&partial);
 	refresh_cache(REFRESH_QUIET);
 
-	if (write_cache(fd, active_cache, active_nr))
+	if (write_cache(fd, active_cache, active_nr) ||
+	    close_lock_file(&false_lock))
 		die("unable to write temporary index file");
 	return false_lock.filename;
 }
