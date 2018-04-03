	transfer_debug("%s is writable", t->dest_name);
	bytes = xwrite(t->dest, t->buf, t->bufuse);
	if (bytes < 0 && errno != EWOULDBLOCK) {
		error_errno("write(%s) failed", t->dest_name);
		return -1;
	} else if (bytes > 0) {
		t->bufuse -= bytes;
