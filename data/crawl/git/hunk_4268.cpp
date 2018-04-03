 	lock = xcalloc(1, sizeof(struct ref_lock));
 	lock->lock_fd = -1;
 
-	ref = resolve_ref(ref, lock->old_sha1, mustexist, &type);
-	if (!ref && errno == EISDIR) {
+	refname = resolve_ref(refname, lock->old_sha1, mustexist, &type);
+	if (!refname && errno == EISDIR) {
 		/* we are trying to lock foo but we used to
 		 * have foo/bar which now does not exist;
 		 * it is normal for the empty directory 'foo'
 		 * to remain.
 		 */
-		ref_file = git_path("%s", orig_ref);
+		ref_file = git_path("%s", orig_refname);
 		if (remove_empty_directories(ref_file)) {
 			last_errno = errno;
-			error("there are still refs under '%s'", orig_ref);
+			error("there are still refs under '%s'", orig_refname);
 			goto error_return;
 		}
-		ref = resolve_ref(orig_ref, lock->old_sha1, mustexist, &type);
+		refname = resolve_ref(orig_refname, lock->old_sha1, mustexist, &type);
 	}
 	if (type_p)
 	    *type_p = type;
-	if (!ref) {
+	if (!refname) {
 		last_errno = errno;
 		error("unable to resolve reference %s: %s",
-			orig_ref, strerror(errno));
+			orig_refname, strerror(errno));
 		goto error_return;
 	}
 	missing = is_null_sha1(lock->old_sha1);
