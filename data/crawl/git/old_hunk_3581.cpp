	if (strbuf_getline(buffer, helper, '\n') == EOF) {
		if (debug)
			fprintf(stderr, "Debug: Remote helper quit.\n");
		die("Reading from helper 'git-remote-%s' failed", name);
	}

	if (debug)