	exit(1);
}

int split_mbox(const char **mbox, const char *dir, int allow_bare, int nr_prec, int skip)
{
	char *name = xmalloc(strlen(dir) + 2 + 3 * sizeof(skip));
	int ret = -1;

	while (*mbox) {
		const char *file = *mbox++;
		FILE *f = !strcmp(file, "-") ? stdin : fopen(file, "r");
		int file_done = 0;

		if ( !f ) {
			error("cannot open mbox %s", file);
			goto out;
		}

		if (fgets(buf, sizeof(buf), f) == NULL) {
			if (f == stdin)
				break; /* empty stdin is OK */
			error("cannot read mbox %s", file);
			goto out;
		}

		while (!file_done) {
			sprintf(name, "%s/%0*d", dir, nr_prec, ++skip);
			file_done = split_one(f, name, allow_bare);
		}

		if (f != stdin)
			fclose(f);
	}
	ret = skip;
out:
	free(name);
	return ret;
}
int cmd_mailsplit(int argc, const char **argv, const char *prefix)
{
	int nr = 0, nr_prec = 4, ret;
	int allow_bare = 0;
	const char *dir = NULL;
	const char **argp;
