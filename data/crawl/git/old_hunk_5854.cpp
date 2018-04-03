	FILE *fp = fopen(filename, "r");

	if (!fp)
		die("Could not open file '%s': %s", filename, strerror(errno));

	while (strbuf_getline(&str, fp, '\n') != EOF) {
		char *quoted;
