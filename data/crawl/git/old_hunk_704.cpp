		    object_ref, typename(obj_type),
		    replace_ref, typename(repl_type));

	check_ref_valid(object, &prev, ref, sizeof(ref), force);

	transaction = ref_transaction_begin(&err);
	if (!transaction ||
	    ref_transaction_update(transaction, ref, repl->hash, prev.hash,
				   0, NULL, &err) ||
	    ref_transaction_commit(transaction, &err))
		die("%s", err.buf);

	ref_transaction_free(transaction);
	return 0;
}

