done:
	git_inflate_end(&stream);
	close(out);
}

static void run_service(const char **argv)
{
	const char *encoding = getenv("HTTP_CONTENT_ENCODING");
	const char *user = getenv("REMOTE_USER");
