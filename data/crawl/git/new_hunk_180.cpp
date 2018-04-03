		}
		if (ref_transaction_delete(transaction,
					   namespaced_name,
					   old_oid,
					   0, "push", &err)) {
			rp_error("%s", err.buf);
			strbuf_release(&err);
