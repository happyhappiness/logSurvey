
		if (ref_transaction_update(transaction,
					   namespaced_name,
					   new_oid, old_oid,
					   0, "push",
					   &err)) {
			rp_error("%s", err.buf);
