			msg = argv[1];
			if (!*msg)
				die("Refusing to perform update with empty message");
		}
		else if (!strcmp("--", arg)) {
			argc--;
