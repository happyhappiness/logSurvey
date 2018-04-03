 	fd = lock_file(lk, path, flags);
 	if (fd < 0) {
 		if (flags & LOCK_DIE_ON_ERROR)
-			die("unable to create '%s.lock': %s", path, strerror(errno));
+			unable_to_lock_index_die(path, errno);
 		return fd;
 	}
 