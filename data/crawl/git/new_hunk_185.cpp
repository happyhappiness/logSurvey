		die("delete %s: extra input: %s", refname, next);

	if (ref_transaction_delete(transaction, refname,
				   have_old ? &old_oid : NULL,
				   update_flags, msg, &err))
		die("%s", err.buf);

