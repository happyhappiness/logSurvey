	send_file("application/x-git-packed-objects-toc", name);
}

static int http_config(const char *var, const char *value, void *cb)
{
	struct rpc_service *svc = cb;

	if (!prefixcmp(var, "http.") &&
	    !strcmp(var + 5, svc->config_name)) {
		svc->enabled = git_config_bool(var, value);
		return 0;
	}

	/* we are not interested in parsing any other configuration here */
	return 0;
}

static struct rpc_service *select_service(const char *name)
{
	struct rpc_service *svc = NULL;
	int i;

	if (prefixcmp(name, "git-"))
		forbidden("Unsupported service: '%s'", name);

	for (i = 0; i < ARRAY_SIZE(rpc_service); i++) {
		struct rpc_service *s = &rpc_service[i];
		if (!strcmp(s->name, name + 4)) {
			svc = s;
			break;
		}
	}

	if (!svc)
		forbidden("Unsupported service: '%s'", name);

	git_config(http_config, svc);
	if (svc->enabled < 0) {
		const char *user = getenv("REMOTE_USER");
		svc->enabled = (user && *user) ? 1 : 0;
	}
	if (!svc->enabled)
		forbidden("Service not enabled: '%s'", svc->name);
	return svc;
}

static void inflate_request(const char *prog_name, int out)
{
	z_stream stream;
	unsigned char in_buf[8192];
	unsigned char out_buf[8192];
	unsigned long cnt = 0;
	int ret;

	memset(&stream, 0, sizeof(stream));
	ret = inflateInit2(&stream, (15 + 16));
	if (ret != Z_OK)
		die("cannot start zlib inflater, zlib err %d", ret);

	while (1) {
		ssize_t n = xread(0, in_buf, sizeof(in_buf));
		if (n <= 0)
			die("request ended in the middle of the gzip stream");

		stream.next_in = in_buf;
		stream.avail_in = n;

		while (0 < stream.avail_in) {
			int ret;

			stream.next_out = out_buf;
			stream.avail_out = sizeof(out_buf);

			ret = inflate(&stream, Z_NO_FLUSH);
			if (ret != Z_OK && ret != Z_STREAM_END)
				die("zlib error inflating request, result %d", ret);

			n = stream.total_out - cnt;
			if (write_in_full(out, out_buf, n) != n)
				die("%s aborted reading request", prog_name);
			cnt += n;

			if (ret == Z_STREAM_END)
				goto done;
		}
	}

done:
	inflateEnd(&stream);
	close(out);
}

static void run_service(const char **argv)
{
	const char *encoding = getenv("HTTP_CONTENT_ENCODING");
	const char *user = getenv("REMOTE_USER");
	const char *host = getenv("REMOTE_ADDR");
	char *env[3];
	struct strbuf buf = STRBUF_INIT;
	int gzipped_request = 0;
	struct child_process cld;

	if (encoding && !strcmp(encoding, "gzip"))
		gzipped_request = 1;
	else if (encoding && !strcmp(encoding, "x-gzip"))
		gzipped_request = 1;

	if (!user || !*user)
		user = "anonymous";
	if (!host || !*host)
		host = "(none)";

	memset(&env, 0, sizeof(env));
	strbuf_addf(&buf, "GIT_COMMITTER_NAME=%s", user);
	env[0] = strbuf_detach(&buf, NULL);

	strbuf_addf(&buf, "GIT_COMMITTER_EMAIL=%s@http.%s", user, host);
	env[1] = strbuf_detach(&buf, NULL);
	env[2] = NULL;

	memset(&cld, 0, sizeof(cld));
	cld.argv = argv;
	cld.env = (const char *const *)env;
	if (gzipped_request)
		cld.in = -1;
	cld.git_cmd = 1;
	if (start_command(&cld))
		exit(1);

	close(1);
	if (gzipped_request)
		inflate_request(argv[0], cld.in);
	else
		close(0);

	if (finish_command(&cld))
		exit(1);
	free(env[0]);
	free(env[1]);
	strbuf_release(&buf);
}

static int show_text_ref(const char *name, const unsigned char *sha1,
	int flag, void *cb_data)
{
