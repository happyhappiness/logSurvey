	return write_archive(sent_argc, sent_argv, prefix, 0);
}

static void error_clnt(const char *fmt, ...)
{
	char buf[1024];
