{
	static struct strbuf buf = STRBUF_INIT;
	int r;
	FILE *fh;

	fh = fopen("/dev/tty", "w+");
	if (!fh)
		return NULL;

	if (!echo && disable_echo()) {
		fclose(fh);
		return NULL;
	}

	fputs(prompt, fh);
	fflush(fh);

	r = strbuf_getline(&buf, fh, '\n');
	if (!echo) {
		fseek(fh, SEEK_CUR, 0);
		putc('\n', fh);
		fflush(fh);
	}

	restore_term();
	fclose(fh);

	if (r == EOF)
		return NULL;