	if (*next != line_termination)
		die("verify %s: extra input: %s", refname, next);

	if (ref_transaction_verify(transaction, refname, &old_oid,
				   update_flags, &err))
		die("%s", err.buf);

