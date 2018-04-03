 
 	if (write_cache(fd, active_cache, active_nr) ||
 	    close_lock_file(&false_lock))
-		die("unable to write temporary index file");
+		die(_("unable to write temporary index file"));
 
 	discard_cache();
 	read_cache_from(false_lock.filename);
