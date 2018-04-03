	return map_sha1_file_1(NULL, sha1, size);
}

static int unpack_sha1_short_header(git_zstream *stream,
				    unsigned char *map, unsigned long mapsize,
				    void *buffer, unsigned long bufsiz)