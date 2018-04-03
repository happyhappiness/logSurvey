
	snprintf(tmpfile, sizeof(tmpfile),
		"%s/tmp_pack_XXXXXX", get_object_directory());
	pack_fd = xmkstemp(tmpfile);
	p = xcalloc(1, sizeof(*p) + strlen(tmpfile) + 2);
	strcpy(p->pack_name, tmpfile);
	p->pack_fd = pack_fd;
