 		die("update %s: extra input: %s", refname, next);
 
 	if (ref_transaction_update(transaction, refname,
-				   new_oid.hash, have_old ? old_oid.hash : NULL,
+				   &new_oid, have_old ? &old_oid : NULL,
 				   update_flags | create_reflog_flag,
 				   msg, &err))
 		die("%s", err.buf);
