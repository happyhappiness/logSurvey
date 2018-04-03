	else
		remote = remote_get(argv[0]);

	transport = transport_get(remote, remote->url[0]);
	if (verbosity >= 2)
		transport->verbose = 1;
