    }
    if (put_file) {
	opt_put = 1;
	/*method = xstrdup("PUT"); */
	put_fd = open(put_file, O_RDONLY);
	set_our_signal();
	if (put_fd < 0) {
	    fprintf(stderr, "%s: can't open file (%s)\n", argv[0],
		xstrerror());
	    exit(-1);
	}
	fstat(put_fd, &sb);
    }
    snprintf(msg, BUFSIZ, "%s %s HTTP/1.0\r\n", method, url);
    if (reload) {
	snprintf(buf, BUFSIZ, "Pragma: no-cache\r\n");
	strcat(msg, buf);
    }
    if (put_fd > 0) {
	snprintf(buf, BUFSIZ, "Content-length: %d\r\n", sb.st_size);
	strcat(msg, buf);
    }
    if (opt_noaccept == 0) {
