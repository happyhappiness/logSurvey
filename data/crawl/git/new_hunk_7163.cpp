		die("unable to write sha1 file");
	free(compressed);

	if (mtime) {
		struct utimbuf utb;
		utb.actime = mtime;
		utb.modtime = mtime;
		if (utime(tmpfile, &utb) < 0)
			warning("failed utime() on %s: %s",
				tmpfile, strerror(errno));
	}

	return move_temp_to_file(tmpfile, filename);
}

int write_sha1_file(void *buf, unsigned long len, const char *type, unsigned char *returnsha1)
{
	unsigned char sha1[20];
	char hdr[32];
	int hdrlen;

	/* Normally if we have it in the pack then we do not bother writing
	 * it out into .git/objects/??/?{38} file.
	 */
	write_sha1_file_prepare(buf, len, type, sha1, hdr, &hdrlen);
	if (returnsha1)
		hashcpy(returnsha1, sha1);
	if (has_sha1_file(sha1))
		return 0;
	return write_loose_object(sha1, hdr, hdrlen, buf, len, 0);
}

int force_object_loose(const unsigned char *sha1, time_t mtime)
{
	struct stat st;
	void *buf;
	unsigned long len;
	enum object_type type;
	char hdr[32];
	int hdrlen;

	if (find_sha1_file(sha1, &st))
		return 0;
	buf = read_packed_sha1(sha1, &type, &len);
	if (!buf)
		return error("cannot read sha1_file for %s", sha1_to_hex(sha1));
	hdrlen = sprintf(hdr, "%s %lu", typename(type), len) + 1;
	return write_loose_object(sha1, hdr, hdrlen, buf, len, mtime);
}

/*
 * We need to unpack and recompress the object for writing
 * it out to a different file.