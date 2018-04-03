	}

	n = 0;
	while (argv[n])
		n++;

	pathspec->nr = n;
	ALLOC_ARRAY(pathspec->items, n);
