	return err;
}

int verify_pack(struct packed_git *p)
{
	off_t index_size;
	const unsigned char *index_base;
