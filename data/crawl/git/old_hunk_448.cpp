		return -1;
	}

	return refs->be->transaction_commit(refs, transaction, err);
}

int refs_verify_refname_available(struct ref_store *refs,
