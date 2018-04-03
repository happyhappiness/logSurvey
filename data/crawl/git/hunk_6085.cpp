 	 */
 	ret |= repack_without_ref(refname);
 
-	err = unlink(git_path("logs/%s", lock->ref_name));
-	if (err && errno != ENOENT)
-		warning("unlink(%s) failed: %s",
-			git_path("logs/%s", lock->ref_name), strerror(errno));
+	unlink_or_warn(git_path("logs/%s", lock->ref_name));
 	invalidate_cached_refs();
 	unlock_ref(lock);
 	return ret;
