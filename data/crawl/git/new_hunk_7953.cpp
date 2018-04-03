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
