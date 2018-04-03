 			continue;
 
 		/*
-		 * Create an entry in the packed-refs cache equivalent
-		 * to the one from the loose ref cache, except that
-		 * we don't copy the peeled status, because we want it
-		 * to be re-peeled.
+		 * Add a reference creation for this reference to the
+		 * packed-refs transaction:
 		 */
-		add_packed_ref(refs->packed_ref_store, iter->refname, iter->oid);
+		if (ref_transaction_update(transaction, iter->refname,
+					   iter->oid->hash, NULL,
+					   REF_NODEREF, NULL, &err))
+			die("failure preparing to create packed reference %s: %s",
+			    iter->refname, err.buf);
 
 		/* Schedule the loose reference for pruning if requested. */
 		if ((flags & PACK_REFS_PRUNE)) {
