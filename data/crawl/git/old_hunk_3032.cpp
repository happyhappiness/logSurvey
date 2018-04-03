	ferr_write(s, strlen(s), fp, err);
}

struct rerere_io {
	int (*getline)(struct strbuf *, struct rerere_io *);
	FILE *output;
	int wrerror;
	/* some more stuff */
};

static void rerere_io_putstr(const char *str, struct rerere_io *io)
{
	if (io->output)
		ferr_puts(str, io->output, &io->wrerror);
}

static void rerere_io_putconflict(int ch, int size, struct rerere_io *io)
{
	char buf[64];
