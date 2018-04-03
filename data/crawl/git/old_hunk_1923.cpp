		args->no_progress = 0;
	if (!server_supports("include-tag"))
		args->include_tag = 0;
	if (server_supports("ofs-delta")) {
		if (args->verbose)
			fprintf(stderr, "Server supports ofs-delta\n");
	} else
		prefer_ofs_delta = 0;

	if ((agent_feature = server_feature_value("agent", &agent_len))) {
		agent_supported = 1;
		if (args->verbose && agent_len)
			fprintf(stderr, "Server version is %.*s\n",
				agent_len, agent_feature);
	}

	if (everything_local(args, &ref, sought, nr_sought)) {