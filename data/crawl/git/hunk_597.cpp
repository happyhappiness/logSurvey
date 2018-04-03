 		struct commit *old_cmit, *new_cmit;
 
 		old_cmit = lookup_commit_reference_gently(old_sha1, 0);
-		new_cmit = lookup_commit_reference_gently(b->sha1, 0);
+		new_cmit = lookup_commit_reference_gently(b->oid.hash, 0);
 		if (!old_cmit || !new_cmit)
 			return error("Branch %s is missing commits.", b->name);
 
 		if (!in_merge_bases(old_cmit, new_cmit)) {
 			warning("Not updating %s"
 				" (new tip %s does not contain %s)",
-				b->name, sha1_to_hex(b->sha1), sha1_to_hex(old_sha1));
+				b->name, oid_to_hex(&b->oid),
+				sha1_to_hex(old_sha1));
 			return -1;
 		}
 	}
 	transaction = ref_transaction_begin(&err);
 	if (!transaction ||
-	    ref_transaction_update(transaction, b->name, b->sha1, old_sha1,
+	    ref_transaction_update(transaction, b->name, b->oid.hash, old_sha1,
 				   0, msg, &err) ||
 	    ref_transaction_commit(transaction, &err)) {
 		ref_transaction_free(transaction);
