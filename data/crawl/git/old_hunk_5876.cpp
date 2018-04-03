{
	struct strbuf buf = STRBUF_INIT;
	if (strbuf_read(&buf, 0, 1024) < 0) {
		die("error reading standard input: %s", strerror(errno));
	}
	return strbuf_detach(&buf, NULL);
}