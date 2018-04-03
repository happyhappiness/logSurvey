				die("option -m needs an argument.");
			if (message)
				die("only one -F or -m option is allowed.");
			message = xstrdup(argv[i]);
			continue;
		}
		if (!strcmp(arg, "-F")) {
			unsigned long len;
			int fd;

			annotate = 1;
