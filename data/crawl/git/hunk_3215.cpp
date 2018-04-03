  rollback:
 	lock = lock_ref_sha1_basic(oldrefname, NULL, NULL, NULL, 0, NULL, &err);
 	if (!lock) {
-		error("%s", err.buf);
+		error("unable to lock %s for rollback: %s", oldrefname, err.buf);
 		strbuf_release(&err);
-		error("unable to lock %s for rollback", oldrefname);
 		goto rollbacklog;
 	}
 