static int get_sha1_basic(const char *str, int len, unsigned char *sha1)
{
	static const char *warn_msg = "refname '%.*s' is ambiguous.";
	char *real_ref = NULL;
	int refs_found = 0;
	int at, reflog_len;

	if (len == 40 && !get_sha1_hex(str, sha1))
		return 0;

	/* basic@{time or number or -number} format to query ref-log */
	reflog_len = at = 0;
