
	strbuf_addf(&key, "remote.%s.fetch", remotename);

	remote = remote_get(remotename);
	if (!remote_is_configured(remote))
		die(_("No such remote '%s'"), remotename);

	if (!add_mode && remove_all_fetch_refspecs(remotename, key.buf)) {
		strbuf_release(&key);
