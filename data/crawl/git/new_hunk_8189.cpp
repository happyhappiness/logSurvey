			msg = argv[++i];
			if (!*msg)
				die("Refusing to perform update with empty message.");
			continue;
		}
		if (!strcmp("-d", argv[i])) {