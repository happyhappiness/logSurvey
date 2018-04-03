	return cmd_log_walk(&rev);
}

static int show_object(const unsigned char *sha1, int suppress_header)
{
	unsigned long size;
	enum object_type type;
