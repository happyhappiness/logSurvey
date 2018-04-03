	return 0;
}

static int crlf_to_git(const char *path, const char *src, size_t len,
                       struct strbuf *buf, int action)
{
	struct text_stat stats;
	char *dst;
