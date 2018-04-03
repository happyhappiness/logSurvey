 {
 	if (!lk->active)
 		die("BUG: get_locked_file_path() called for unlocked object");
-	if (lk->filename.len <= LOCK_SUFFIX_LEN)
+	if (lk->filename.len <= LOCK_SUFFIX_LEN ||
+	    strcmp(lk->filename.buf + lk->filename.len - LOCK_SUFFIX_LEN, LOCK_SUFFIX))
 		die("BUG: get_locked_file_path() called for malformed lock object");
+	/* remove ".lock": */
 	return xmemdupz(lk->filename.buf, lk->filename.len - LOCK_SUFFIX_LEN);
 }
 
