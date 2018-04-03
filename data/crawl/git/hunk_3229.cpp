 	 * our refname.
 	 */
 	if (is_null_sha1(lock->old_sha1) &&
-	    verify_refname_available(refname, extras, skip, get_packed_refs(&ref_cache))) {
+	    verify_refname_available(refname, extras, skip,
+				     get_packed_refs(&ref_cache), &err)) {
+		error("%s", err.buf);
 		last_errno = ENOTDIR;
 		goto error_return;
 	}
