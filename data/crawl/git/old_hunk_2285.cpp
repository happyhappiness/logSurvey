
	remotename = argv[0];

	if (!remote_is_configured(remotename))
		die(_("No such remote '%s'"), remotename);
	remote = remote_get(remotename);

	url_nr = 0;
	if (push_mode) {