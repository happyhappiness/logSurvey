	struct child_process rsync;
	const char *args[10];

	if (flags & TRANSPORT_PUSH_MIRROR)
		return error("rsync transport does not support mirror mode");

	/* first push the objects */

	strbuf_addstr(&buf, transport->url);
