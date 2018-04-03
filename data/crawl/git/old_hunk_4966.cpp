		die("not a valid object: %s", buffer.buf);
}

static void reset_hard(unsigned const char *sha1, int verbose)
{
	int i = 0;
