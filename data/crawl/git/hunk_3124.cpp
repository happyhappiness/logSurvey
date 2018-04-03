 		goto cleanup;
 	}
 
+	/*
+	 * It's really undefined to call this function in an active
+	 * repository or when there are existing references: we are
+	 * only locking and changing packed-refs, so (1) any
+	 * simultaneous processes might try to change a reference at
+	 * the same time we do, and (2) any existing loose versions of
+	 * the references that we are setting would have precedence
+	 * over our values. But some remote helpers create the remote
+	 * "HEAD" and "master" branches before calling this function,
+	 * so here we really only check that none of the references
+	 * that we are creating already exists.
+	 */
+	if (for_each_rawref(ref_present, &affected_refnames))
+		die("BUG: initial ref transaction called with existing refs");
+
 	for (i = 0; i < n; i++) {
 		struct ref_update *update = updates[i];
 
 		if ((update->flags & REF_HAVE_OLD) &&
 		    !is_null_sha1(update->old_sha1))
 			die("BUG: initial ref transaction with old_sha1 set");
+		if (verify_refname_available(update->refname,
+					     &affected_refnames, NULL,
+					     loose_refs, err) ||
+		    verify_refname_available(update->refname,
+					     &affected_refnames, NULL,
+					     packed_refs, err)) {
+			ret = TRANSACTION_NAME_CONFLICT;
+			goto cleanup;
+		}
 	}
 
 	if (lock_packed_refs(0)) {