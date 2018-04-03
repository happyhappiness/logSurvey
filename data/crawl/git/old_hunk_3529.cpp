	return 0;
}

static void print_object_or_die(int fd, const unsigned char *sha1,
				enum object_type type, unsigned long size)
{
