	return write_archive(sent_argc, sent_argv, prefix, 0);
}

__attribute__((format (printf, 1, 2)))
static void error_clnt(const char *fmt, ...)
{
	char buf[1024];
