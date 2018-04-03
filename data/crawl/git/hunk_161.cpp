 
 	logmoved = log;
 
-	lock = lock_ref_sha1_basic(refs, newrefname, NULL, NULL, NULL,
-				   REF_NODEREF, NULL, &err);
+	lock = lock_ref_oid_basic(refs, newrefname, NULL, NULL, NULL,
+				  REF_NODEREF, NULL, &err);
 	if (!lock) {
 		if (copy)
 			error("unable to copy '%s' to '%s': %s", oldrefname, newrefname, err.buf);
