				&update->type,
				err);
		if (!update->lock) {
			char *reason;

			ret = (errno == ENOTDIR)
				? TRANSACTION_NAME_CONFLICT
				: TRANSACTION_GENERIC_ERROR;
			reason = strbuf_detach(err, NULL);
			strbuf_addf(err, "Cannot lock the ref '%s': %s",
				    update->refname, reason);
			free(reason);
			goto cleanup;
		}
	}