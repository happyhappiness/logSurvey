		die("HTTP request failed");
	}

	last= xcalloc(1, sizeof(*last_discovery));
	last->service = service;
	last->buf_alloc = strbuf_detach(&buffer, &last->len);
	last->buf = last->buf_alloc;

	if (is_http && 5 <= last->len && last->buf[4] == '#') {
		/* smart HTTP response; validate that the service
		 * pkt-line matches our request.
		 */
		struct strbuf exp = STRBUF_INIT;

		if (packet_get_line(&buffer, &last->buf, &last->len) <= 0)
			die("%s has invalid packet header", refs_url);
		if (buffer.len && buffer.buf[buffer.len - 1] == '\n')
			strbuf_setlen(&buffer, buffer.len - 1);

		strbuf_addf(&exp, "# service=%s", service);
		if (strbuf_cmp(&exp, &buffer))
			die("invalid server response; got '%s'", buffer.buf);
		strbuf_release(&exp);

		/* The header can include additional metadata lines, up
		 * until a packet flush marker.  Ignore these now, but
		 * in the future we might start to scan them.
		 */
		strbuf_reset(&buffer);
		while (packet_get_line(&buffer, &last->buf, &last->len) > 0)
			strbuf_reset(&buffer);

		last->proto_git = 1;
	}

	free(refs_url);
	strbuf_release(&buffer);
	last_discovery = last;
	return last;
}

static int write_discovery(int fd, void *data)
{
	struct discovery *heads = data;
	int err = 0;
	if (write_in_full(fd, heads->buf, heads->len) != heads->len)
		err = 1;
	close(fd);
	return err;
}

static struct ref *parse_git_refs(struct discovery *heads)
{
	struct ref *list = NULL;
	struct async async;

	memset(&async, 0, sizeof(async));
	async.proc = write_discovery;
	async.data = heads;

	if (start_async(&async))
		die("cannot start thread to parse advertised refs");
	get_remote_heads(async.out, &list, 0, NULL, 0, NULL);
	close(async.out);
	if (finish_async(&async))
		die("ref parsing thread failed");
	return list;
}

static struct ref *parse_info_refs(struct discovery *heads)
{
	char *data, *start, *mid;
	char *ref_name;
	int i = 0;

	struct ref *refs = NULL;
	struct ref *ref = NULL;
	struct ref *last_ref = NULL;

	data = heads->buf;
	start = NULL;
	mid = data;
	while (i < heads->len) {
		if (!start) {
			start = &data[i];
		}
