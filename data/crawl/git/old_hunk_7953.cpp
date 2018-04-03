			continue;
		}
		if (!strcmp(arg, "-F")) {
			int fd;

			annotate = 1;
			i++;
			if (i == argc)
				die("option -F needs an argument.");
			if (message)
				die("only one -F or -m option is allowed.");

			if (!strcmp(argv[i], "-"))
				fd = 0;
			else {
				fd = open(argv[i], O_RDONLY);
				if (fd < 0)
					die("could not open '%s': %s",
						argv[i], strerror(errno));
			}
			if (strbuf_read(&buf, fd, 1024) < 0) {
				die("cannot read %s", argv[i]);
			}
			message = 1;
			continue;
		}