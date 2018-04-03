	return write_loose_object(sha1, hdr, hdrlen, buf, len, mtime);
}

/*
 * We need to unpack and recompress the object for writing
 * it out to a different file.
 */
static void *repack_object(const unsigned char *sha1, unsigned long *objsize)
{
	size_t size;
	z_stream stream;
	unsigned char *unpacked;
	unsigned long len;
	enum object_type type;
	char hdr[32];
	int hdrlen;
	void *buf;

	/* need to unpack and recompress it by itself */
	unpacked = read_packed_sha1(sha1, &type, &len);
	if (!unpacked)
		error("cannot read sha1_file for %s", sha1_to_hex(sha1));

	hdrlen = sprintf(hdr, "%s %lu", typename(type), len) + 1;

	/* Set it up */
	memset(&stream, 0, sizeof(stream));
	deflateInit(&stream, zlib_compression_level);
	size = deflateBound(&stream, len + hdrlen);
	buf = xmalloc(size);

	/* Compress it */
	stream.next_out = buf;
	stream.avail_out = size;

	/* First header.. */
	stream.next_in = (void *)hdr;
	stream.avail_in = hdrlen;
	while (deflate(&stream, 0) == Z_OK)
		/* nothing */;

	/* Then the data itself.. */
	stream.next_in = unpacked;
	stream.avail_in = len;
	while (deflate(&stream, Z_FINISH) == Z_OK)
		/* nothing */;
	deflateEnd(&stream);
	free(unpacked);

	*objsize = stream.total_out;
	return buf;
}

int write_sha1_to_fd(int fd, const unsigned char *sha1)
{
	int retval;
	unsigned long objsize;
	void *buf = map_sha1_file(sha1, &objsize);

	if (buf) {
		retval = write_buffer(fd, buf, objsize);
		munmap(buf, objsize);
		return retval;
	}

	buf = repack_object(sha1, &objsize);
	retval = write_buffer(fd, buf, objsize);
	free(buf);
	return retval;
}

int write_sha1_from_fd(const unsigned char *sha1, int fd, char *buffer,
		       size_t bufsize, size_t *bufposn)
{
	char tmpfile[PATH_MAX];
	int local;
	z_stream stream;
	unsigned char real_sha1[20];
	unsigned char discard[4096];
	int ret;
	SHA_CTX c;

	snprintf(tmpfile, sizeof(tmpfile), "%s/tmp_obj_XXXXXX", get_object_directory());

	local = mkstemp(tmpfile);
	if (local < 0) {
		if (errno == EPERM)
			return error("insufficient permission for adding an object to repository database %s\n", get_object_directory());
		else
			return error("unable to create temporary sha1 filename %s: %s\n", tmpfile, strerror(errno));
	}

	memset(&stream, 0, sizeof(stream));

	inflateInit(&stream);

	SHA1_Init(&c);

	do {
		ssize_t size;
		if (*bufposn) {
			stream.avail_in = *bufposn;
			stream.next_in = (unsigned char *) buffer;
			do {
				stream.next_out = discard;
				stream.avail_out = sizeof(discard);
				ret = inflate(&stream, Z_SYNC_FLUSH);
				SHA1_Update(&c, discard, sizeof(discard) -
					    stream.avail_out);
			} while (stream.avail_in && ret == Z_OK);
			if (write_buffer(local, buffer, *bufposn - stream.avail_in) < 0)
				die("unable to write sha1 file");
			memmove(buffer, buffer + *bufposn - stream.avail_in,
				stream.avail_in);
			*bufposn = stream.avail_in;
			if (ret != Z_OK)
				break;
		}
		size = xread(fd, buffer + *bufposn, bufsize - *bufposn);
		if (size <= 0) {
			close(local);
			unlink(tmpfile);
			if (!size)
				return error("Connection closed?");
			perror("Reading from connection");
			return -1;
		}
		*bufposn += size;
	} while (1);
	inflateEnd(&stream);

	close_sha1_file(local);
	SHA1_Final(real_sha1, &c);
	if (ret != Z_STREAM_END) {
		unlink(tmpfile);
		return error("File %s corrupted", sha1_to_hex(sha1));
	}
	if (hashcmp(sha1, real_sha1)) {
		unlink(tmpfile);
		return error("File %s has bad hash", sha1_to_hex(sha1));
	}

	return move_temp_to_file(tmpfile, sha1_file_name(sha1));
}

int has_pack_index(const unsigned char *sha1)
{
	struct stat st;