			sha1_to_hex(commit->object.sha1));
}

static void advise(const char *advice, ...)
{
	va_list params;
