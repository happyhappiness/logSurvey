	const char *head;
	if (our && skip_prefix(our->name, "refs/heads/", &head)) {
		/* Local default branch link */
		create_symref("HEAD", our->name, NULL);
		if (!option_bare) {
			update_ref(msg, "HEAD", our->old_oid.hash, NULL, 0,
				   UPDATE_REFS_DIE_ON_ERR);
