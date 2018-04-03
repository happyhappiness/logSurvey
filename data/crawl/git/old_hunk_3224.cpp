				 update->old_sha1 : NULL),
				&affected_refnames, NULL,
				flags,
				&update->type);
		if (!update->lock) {
			ret = (errno == ENOTDIR)
				? TRANSACTION_NAME_CONFLICT
				: TRANSACTION_GENERIC_ERROR;
			strbuf_addf(err, "Cannot lock the ref '%s'.",
				    update->refname);
			goto cleanup;
