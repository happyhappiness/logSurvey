	int exit_code;

	if (!remote)
		die("Where do you want to fetch from today?");

	transport = transport_get(remote, NULL);
	transport_set_verbosity(transport, verbosity, progress);
