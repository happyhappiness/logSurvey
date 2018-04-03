		struct remote *remote = remote_get(argv[0]);
		struct transport *transport = transport_get(remote, argv[0]);

		transport_set_option(transport, TRANS_OPT_KEEP, "yes");

		if (option_depth)