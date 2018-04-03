 		return -1;
 	if (write_cache(fd, active_cache, active_nr) ||
 		commit_locked_index(lock_file))
-		die("unable to write new index file");
+		die(_("unable to write new index file"));
 	return 0;
 }
 
