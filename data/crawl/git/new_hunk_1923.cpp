		args->no_progress = 0;
	if (!server_supports("include-tag"))
		args->include_tag = 0;
	if (server_supports("ofs-delta"))
		print_verbose(args, "Server supports ofs-delta");
	else
		prefer_ofs_delta = 0;

	if ((agent_feature = server_feature_value("agent", &agent_len))) {
		agent_supported = 1;
		if (agent_len)
			print_verbose(args, "Server version is %.*s",
				      agent_len, agent_feature);
	}

	if (everything_local(args, &ref, sought, nr_sought)) {