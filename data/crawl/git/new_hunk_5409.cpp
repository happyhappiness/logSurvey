	/* Then the data itself.. */
	stream.next_in = buf;
	stream.avail_in = len;
	do {
		ret = deflate(&stream, Z_FINISH);
		if (write_buffer(fd, compressed, stream.next_out - compressed) < 0)
			die("unable to write sha1 file");
		stream.next_out = compressed;
		stream.avail_out = sizeof(compressed);
	} while (ret == Z_OK);

	if (ret != Z_STREAM_END)
		die("unable to deflate new object %s (%d)", sha1_to_hex(sha1), ret);
	ret = deflateEnd(&stream);
	if (ret != Z_OK)
		die("deflateEnd on object %s failed (%d)", sha1_to_hex(sha1), ret);

	close_sha1_file(fd);

	if (mtime) {
		struct utimbuf utb;