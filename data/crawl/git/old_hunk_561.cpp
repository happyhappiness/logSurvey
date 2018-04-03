		if (!strcmp(remote_ref->name, symref))
			return error("Remote branch %s is the current HEAD",
				     remote_ref->name);
		fetch_symref(symref, &symref, head_sha1);
	}

	/* Run extra sanity checks if delete is not forced */
	if (!force) {
		/* Remote HEAD must resolve to a known object */
		if (symref)
			return error("Remote HEAD symrefs too deep");
		if (is_null_sha1(head_sha1))
			return error("Unable to resolve remote HEAD");
		if (!has_sha1_file(head_sha1))
			return error("Remote HEAD resolves to object %s\nwhich does not exist locally, perhaps you need to fetch?", sha1_to_hex(head_sha1));

		/* Remote branch must resolve to a known object */
		if (is_null_oid(&remote_ref->old_oid))
