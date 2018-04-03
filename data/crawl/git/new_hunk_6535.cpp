	stream.avail_out = obj->size;
	stream.next_in = src;
	stream.avail_in = len;
	git_inflate_init(&stream);
	while ((st = git_inflate(&stream, Z_FINISH)) == Z_OK);
	git_inflate_end(&stream);
	if (st != Z_STREAM_END || stream.total_out != obj->size)
		die("serious inflate inconsistency");
	free(src);
