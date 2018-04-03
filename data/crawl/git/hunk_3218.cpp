 	 */
 	if (is_null_sha1(lock->old_sha1) &&
 	    verify_refname_available(refname, extras, skip,
-				     get_packed_refs(&ref_cache), &err)) {
-		error("%s", err.buf);
+				     get_packed_refs(&ref_cache), err)) {
 		last_errno = ENOTDIR;
 		goto error_return;
 	}
