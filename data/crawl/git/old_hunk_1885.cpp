		deepen_since_ok = 1;
	else if (args->deepen_since)
		die(_("Server does not support --shallow-since"));

	if (everything_local(args, &ref, sought, nr_sought)) {
		packet_flush(fd[1]);
