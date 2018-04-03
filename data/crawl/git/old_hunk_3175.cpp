	return svc;
}

static void inflate_request(const char *prog_name, int out)
{
	git_zstream stream;
	unsigned char in_buf[8192];
	unsigned char out_buf[8192];
	unsigned long cnt = 0;
