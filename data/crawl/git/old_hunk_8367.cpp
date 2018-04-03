
int verify_pack(struct packed_git *p, int verbose)
{
	off_t index_size = p->index_size;
	const unsigned char *index_base = p->index_data;
	SHA_CTX ctx;
	unsigned char sha1[20];
	int ret;

	ret = 0;
	/* Verify SHA1 sum of the index file */
	SHA1_Init(&ctx);
