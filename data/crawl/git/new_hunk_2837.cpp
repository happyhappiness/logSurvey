	packet_trace_identity("push");
	git_config(git_push_config, &flags);
	argc = parse_options(argc, argv, prefix, options, push_usage, 0);
	set_push_cert_flags(&flags, push_cert);

	if (deleterefs && (tags || (flags & (TRANSPORT_PUSH_ALL | TRANSPORT_PUSH_MIRROR))))
		die(_("--delete is incompatible with --all, --mirror and --tags"));
