	transfer_debug("%s is writable", t->dest_name);
	bytes = xwrite(t->dest, t->buf, t->bufuse);
	if (bytes < 0 && errno != EWOULDBLOCK) {
		error("write(%s) failed: %s", t->dest_name, strerror(errno));
		return -1;
	} else if (bytes > 0) {
		t->bufuse -= bytes;
