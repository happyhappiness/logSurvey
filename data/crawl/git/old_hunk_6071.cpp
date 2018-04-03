	unsigned long orig_size = size;

	if (memcmp(buffer, "tree ", 5))
		die("Bad commit '%s'", (char*) buffer);
	convert_ascii_sha1((char *) buffer + 5);
	buffer = (char *) buffer + 46;    /* "tree " + "hex sha1" + "\n" */
	while (!memcmp(buffer, "parent ", 7)) {
