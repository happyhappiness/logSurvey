{
	struct strbuf buf;
	unsigned char object[20], prev[20];
	int annotate = 0, sign = 0, force = 0, lines = 0, message = 0;
	char ref[PATH_MAX];
	const char *object_ref, *tag;
	int i;
	struct ref_lock *lock;

	git_config(git_tag_config);
	strbuf_init(&buf, 0);

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];

		if (arg[0] != '-')
			break;
		if (!strcmp(arg, "-a")) {
			annotate = 1;
			continue;
		}
		if (!strcmp(arg, "-s")) {
			annotate = 1;
			sign = 1;
			continue;
		}
		if (!strcmp(arg, "-f")) {
			force = 1;
			continue;
		}
		if (!strcmp(arg, "-n")) {
			if (i + 1 == argc || *argv[i + 1] == '-')
				/* no argument */
				lines = 1;
			else
				lines = isdigit(*argv[++i]) ?
					atoi(argv[i]) : 1;
			continue;
		}
		if (!strcmp(arg, "-m")) {
			annotate = 1;
			i++;
			if (i == argc)
				die("option -m needs an argument.");
			if (message)
				die("only one -F or -m option is allowed.");
			strbuf_addstr(&buf, argv[i]);
			message = 1;
			continue;
		}
		if (!strcmp(arg, "-F")) {
			annotate = 1;
			i++;
			if (i == argc)
				die("option -F needs an argument.");
			if (message)
				die("only one -F or -m option is allowed.");

			if (!strcmp(argv[i], "-")) {
				if (strbuf_read(&buf, 0, 1024) < 0)
					die("cannot read %s", argv[i]);
			} else {
				if (strbuf_read_file(&buf, argv[i], 1024) < 0)
					die("could not open or read '%s': %s",
						argv[i], strerror(errno));
			}
			message = 1;
			continue;
		}
		if (!strcmp(arg, "-u")) {
			annotate = 1;
			sign = 1;
			i++;
			if (i == argc)
				die("option -u needs an argument.");
			if (strlcpy(signingkey, argv[i], sizeof(signingkey))
							>= sizeof(signingkey))
				die("argument to option -u too long");
			continue;
		}
		if (!strcmp(arg, "-l"))
			return list_tags(argv[i + 1], lines);
		if (!strcmp(arg, "-d"))
			return for_each_tag_name(argv + i + 1, delete_tag);
		if (!strcmp(arg, "-v"))
			return for_each_tag_name(argv + i + 1, verify_tag);
		usage(builtin_tag_usage);
	}

	if (i == argc) {
		if (annotate)
			usage(builtin_tag_usage);
		return list_tags(NULL, lines);
	}
	tag = argv[i++];

	object_ref = i < argc ? argv[i] : "HEAD";
	if (i + 1 < argc)
		die("too many params");

	if (get_sha1(object_ref, object))
