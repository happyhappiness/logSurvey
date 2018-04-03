			print_verbose(args, _("Server version is %.*s"),
				      agent_len, agent_feature);
	}
	if (server_supports("deepen-since"))
		deepen_since_ok = 1;
	else if (args->deepen_since)
		die(_("Server does not support --shallow-since"));

	if (everything_local(args, &ref, sought, nr_sought)) {
		packet_flush(fd[1]);
