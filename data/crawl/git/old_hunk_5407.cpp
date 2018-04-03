	ret = deflateEnd(&stream);
	if (ret != Z_OK)
		die("deflateEnd on object %s failed (%d)", sha1_to_hex(sha1), ret);

	close_sha1_file(fd);
