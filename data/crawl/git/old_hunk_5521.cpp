			name, transport->url);
}

int cmd_fetch(int argc, const char **argv, const char *prefix)
{
	struct remote *remote;
	int i;
	static const char **refs = NULL;
	int ref_nr = 0;
	int exit_code;

	/* Record the command line for the reflog */
	strbuf_addstr(&default_rla, "fetch");
	for (i = 1; i < argc; i++)
		strbuf_addf(&default_rla, " %s", argv[i]);

	argc = parse_options(argc, argv, prefix,
			     builtin_fetch_options, builtin_fetch_usage, 0);

	if (argc == 0)
		remote = remote_get(NULL);
	else
		remote = remote_get(argv[0]);

	if (!remote)
		die("Where do you want to fetch from today?");

