		strbuf_reset(&refname);
		strbuf_addf(&refname, "refs/%s", write_ref[i]);
		if (ref_transaction_update(transaction, refname.buf,
					   oids[i].hash, NULL, 0,
					   msg ? msg : "fetch (unknown)",
					   &err)) {
			error("%s", err.buf);