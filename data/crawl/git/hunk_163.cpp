 	struct ref_lock *lock;
 	int ret;
 
-	lock = lock_ref_sha1_basic(refs, refname, NULL,
-				   NULL, NULL, REF_NODEREF, NULL,
-				   &err);
+	lock = lock_ref_oid_basic(refs, refname, NULL,
+				  NULL, NULL, REF_NODEREF, NULL,
+				  &err);
 	if (!lock) {
 		error("%s", err.buf);
 		strbuf_release(&err);
