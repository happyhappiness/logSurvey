static void write_item(const char *what, LPCWSTR wbuf, int wlen)
{
	char *buf;
	int len = WideCharToMultiByte(CP_UTF8, 0, wbuf, wlen, NULL, 0, NULL,
	    FALSE);
	buf = xmalloc(len);
