	return has_loose_object(sha1);
}

static int index_mem(unsigned char *sha1, void *buf, size_t size,
		     int write_object, enum object_type type, const char *path)
{
	int ret, re_allocated = 0;

