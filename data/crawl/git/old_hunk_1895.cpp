			print_verbose(args, _("Server version is %.*s"),
				      agent_len, agent_feature);
	}

	if (everything_local(args, &ref, sought, nr_sought)) {
		packet_flush(fd[1]);
