		strbuf_addf(&ref_name, "refs/tags/%s", t->name);

		if (ref_transaction_update(transaction, ref_name.buf,
					   t->sha1, NULL, 0, msg, &err)) {
			failure |= error("%s", err.buf);
			goto cleanup;
		}
