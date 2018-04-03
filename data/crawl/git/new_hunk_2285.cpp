
	remotename = argv[0];

	remote = remote_get(remotename);
	if (!remote_is_configured(remote))
		die(_("No such remote '%s'"), remotename);

	url_nr = 0;
	if (push_mode) {
