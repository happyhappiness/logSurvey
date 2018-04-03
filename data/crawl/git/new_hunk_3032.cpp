	ferr_write(s, strlen(s), fp, err);
}

static void rerere_io_putstr(const char *str, struct rerere_io *io)
{
	if (io->output)
		ferr_puts(str, io->output, &io->wrerror);
}

/*
 * Write a conflict marker to io->output (if defined).
 */
static void rerere_io_putconflict(int ch, int size, struct rerere_io *io)
{
	char buf[64];
