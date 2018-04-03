	return 0;
}

static int write_loose_object(const unsigned char *sha1, char *hdr, int hdrlen,
			      void *buf, unsigned long len, time_t mtime)
{
