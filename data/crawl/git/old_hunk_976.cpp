	struct commit *head_commit;

	if (!resolve_ref_unsafe("HEAD", RESOLVE_REF_READING, head_sha1, NULL))
		return error(_("Could not resolve HEAD commit\n"));

	head_commit = lookup_commit(head_sha1);

