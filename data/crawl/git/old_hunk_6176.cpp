		ps_matched = xcalloc(1, num);
	}

	if (dir.show_ignored && !exc_given) {
		fprintf(stderr, "%s: --ignored needs some exclude pattern\n",
			argv[0]);
		exit(1);
