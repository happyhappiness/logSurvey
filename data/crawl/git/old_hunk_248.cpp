			continue;

		/*
		 * Create an entry in the packed-refs cache equivalent
		 * to the one from the loose ref cache, except that
		 * we don't copy the peeled status, because we want it
		 * to be re-peeled.
		 */
		add_packed_ref(refs->packed_ref_store, iter->refname, iter->oid);

		/* Schedule the loose reference for pruning if requested. */
		if ((flags & PACK_REFS_PRUNE)) {
