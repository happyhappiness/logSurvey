 			   unsigned int flags, const char *msg,
 			   struct strbuf *err)
 {
-	struct ref_update *update;
-
 	assert(err);
 
-	if (transaction->state != REF_TRANSACTION_OPEN)
-		die("BUG: update called for transaction that is not open");
-
-	if ((flags & REF_ISPRUNING) && !(flags & REF_NODEREF))
-		die("BUG: REF_ISPRUNING set without REF_NODEREF");
-
 	if (new_sha1 && !is_null_sha1(new_sha1) &&
 	    check_refname_format(refname, REFNAME_ALLOW_ONELEVEL)) {
 		strbuf_addf(err, "refusing to update ref with bad name '%s'",
 			    refname);
 		return -1;
 	}
 
-	update = add_update(transaction, refname);
-	if (new_sha1) {
-		hashcpy(update->new_sha1, new_sha1);
-		flags |= REF_HAVE_NEW;
-	}
-	if (old_sha1) {
-		hashcpy(update->old_sha1, old_sha1);
-		flags |= REF_HAVE_OLD;
-	}
-	update->flags = flags;
-	if (msg)
-		update->msg = xstrdup(msg);
+	flags |= (new_sha1 ? REF_HAVE_NEW : 0) | (old_sha1 ? REF_HAVE_OLD : 0);
+
+	ref_transaction_add_update(transaction, refname, flags,
+				   new_sha1, old_sha1, msg);
 	return 0;
 }
 
