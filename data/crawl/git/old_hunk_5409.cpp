	/* Then the data itself.. */
	stream.next_in = buf;
	stream.avail_in = len;
	ret = deflate(&stream, Z_FINISH);
	if (ret != Z_STREAM_END)
		die("unable to deflate new object %s (%d)", sha1_to_hex(sha1), ret);

	ret = deflateEnd(&stream);
	if (ret != Z_OK)
		die("deflateEnd on object %s failed (%d)", sha1_to_hex(sha1), ret);

	size = stream.total_out;

	if (write_buffer(fd, compressed, size) < 0)
		die("unable to write sha1 file");
	close_sha1_file(fd);
	free(compressed);

	if (mtime) {
		struct utimbuf utb;