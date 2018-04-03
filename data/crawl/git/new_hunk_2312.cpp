		else if (!strcmp(argv[i], "--"))
			i++;
		else {
			j = diff_opt_parse(&revs->diffopt, argv + i, argc - i,
					   revs->prefix);
			if (j <= 0)
				die("invalid diff option/value: %s", argv[i]);
			i += j;
