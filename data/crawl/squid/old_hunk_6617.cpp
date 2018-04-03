	opt_put = 1;
	method = xstrdup("PUT");
	put_fd = open(put_file, O_RDONLY);
	if (put_fd < 0) {
	    fprintf(stderr, "%s: can't open file (%s)\n", argv[0],
		xstrerror());
