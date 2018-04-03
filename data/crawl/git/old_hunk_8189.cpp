			msg = argv[++i];
			if (!*msg)
				die("Refusing to perform update with empty message.");
			if (strchr(msg, '\n'))
				die("Refusing to perform update with \\n in message.");
			continue;
		}
		if (!strcmp("-d", argv[i])) {