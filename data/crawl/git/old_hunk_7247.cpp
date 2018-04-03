		return 1;
	}
	if (!server.host) {
		fprintf( stderr, "no imap host specified\n" );
		return 1;
	}

	/* read the messages */