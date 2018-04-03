	struct child_process rsync;
	const char *args[10];

	/* first push the objects */

	strbuf_addstr(&buf, transport->url);
