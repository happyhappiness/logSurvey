	return 0;
}

static int grep_buffer_1(struct grep_opt *opt, const char *name,
			 char *buf, unsigned long size, int collect_hits)
{
