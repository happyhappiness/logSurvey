		die ("Could not make temporary directory");
	temp_dir_len = temp_dir.len;

	strbuf_addstr(&buf, transport->url);
	strbuf_addstr(&buf, "/refs");

	memset(&rsync, 0, sizeof(rsync));
