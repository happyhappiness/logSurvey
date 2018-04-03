	if (!buf)
		die ("Could not read blob %s", sha1_to_hex(sha1));

	mark_object(object);

	printf("blob\nmark :%d\ndata %lu\n", last_idnum, size);
	if (size && fwrite(buf, size, 1, stdout) != 1)
