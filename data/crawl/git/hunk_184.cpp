 	if (*next != line_termination)
 		die("create %s: extra input: %s", refname, next);
 
-	if (ref_transaction_create(transaction, refname, new_oid.hash,
+	if (ref_transaction_create(transaction, refname, &new_oid,
 				   update_flags | create_reflog_flag,
 				   msg, &err))
 		die("%s", err.buf);
