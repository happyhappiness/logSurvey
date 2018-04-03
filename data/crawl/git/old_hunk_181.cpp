
		if (ref_transaction_update(transaction,
					   namespaced_name,
					   new_oid->hash, old_oid->hash,
					   0, "push",
					   &err)) {
			rp_error("%s", err.buf);
