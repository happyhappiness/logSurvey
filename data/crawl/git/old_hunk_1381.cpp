
	fd = open(p, O_RDONLY);
	if (fd < 0)
		not_found("Cannot open '%s': %s", p, strerror(errno));
	if (fstat(fd, &sb) < 0)
		die_errno("Cannot stat '%s'", p);

	hdr_int(content_length, sb.st_size);
	hdr_str(content_type, the_type);
	hdr_date(last_modified, sb.st_mtime);
	end_headers();

	for (;;) {
		ssize_t n = xread(fd, buf, buf_alloc);
