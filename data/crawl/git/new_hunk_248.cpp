			continue;

		/*
		 * Add a reference creation for this reference to the
		 * packed-refs transaction:
		 */
		if (ref_transaction_update(transaction, iter->refname,
					   iter->oid->hash, NULL,
					   REF_NODEREF, NULL, &err))
			die("failure preparing to create packed reference %s: %s",
			    iter->refname, err.buf);

		/* Schedule the loose reference for pruning if requested. */
		if ((flags & PACK_REFS_PRUNE)) {
