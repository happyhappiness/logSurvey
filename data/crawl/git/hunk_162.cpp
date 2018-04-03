 	goto out;
 
  rollback:
-	lock = lock_ref_sha1_basic(refs, oldrefname, NULL, NULL, NULL,
-				   REF_NODEREF, NULL, &err);
+	lock = lock_ref_oid_basic(refs, oldrefname, NULL, NULL, NULL,
+				  REF_NODEREF, NULL, &err);
 	if (!lock) {
 		error("unable to lock %s for rollback: %s", oldrefname, err.buf);
 		strbuf_release(&err);
