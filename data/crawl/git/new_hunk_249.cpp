	if (ok != ITER_DONE)
		die("error while iterating over references");

	if (ref_transaction_commit(transaction, &err))
		die("unable to write new packed-refs: %s", err.buf);

	ref_transaction_free(transaction);

	packed_refs_unlock(refs->packed_ref_store);

	prune_refs(refs, refs_to_prune);