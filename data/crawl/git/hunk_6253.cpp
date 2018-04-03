 
 	err = unlink(git_path("logs/%s", lock->ref_name));
 	if (err && errno != ENOENT)
-		fprintf(stderr, "warning: unlink(%s) failed: %s",
+		warning("unlink(%s) failed: %s",
 			git_path("logs/%s", lock->ref_name), strerror(errno));
 	invalidate_cached_refs();
 	unlock_ref(lock);
