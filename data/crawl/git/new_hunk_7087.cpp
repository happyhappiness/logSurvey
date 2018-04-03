	return write_loose_object(sha1, hdr, hdrlen, buf, len, mtime);
}

int has_pack_index(const unsigned char *sha1)
{
	struct stat st;