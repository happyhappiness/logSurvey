	}
	if (argc - i != 3) /* "--" "<head>" "<remote>" */
		die("Not handling anything other than two heads merge.");
	if (verbosity >= 5)
		buffer_output = 0;

	branch1 = argv[++i];
	branch2 = argv[++i];
