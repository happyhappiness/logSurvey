    const char *end;
    const char *url;
    static char buf[READ_BUF_SZ];
    int hlen, blen;
    if (len < 0) {
	perror("read");
	Requests = r->next;
	request_done(r);
	free(r);
	noutstanding--;
	if (trace_fd >= 0)
	    write(trace_fd, "\n[CLOSED]\n", 10);
	return -1;
    }
    total_bytes_read += len;
    xmemcpy(buf, inbuf, len);
    if (len == 0) {
	fprintf(stderr, "WARNING: %s, server closed socket after %d+%d bytes\n", r->url, r->hdr_offset, r->bytes_read);
	/* XXX, If no data was received and it isn't the first request on this
