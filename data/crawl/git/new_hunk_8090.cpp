				die("option -m needs an argument.");
			if (message)
				die("only one -F or -m option is allowed.");
			strbuf_addstr(&buf, argv[i]);
			message = 1;
			continue;
		}
		if (!strcmp(arg, "-F")) {
			int fd;

			annotate = 1;
