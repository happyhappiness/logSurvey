		die("could not chdir to user's home directory");
}

static struct commands {
	const char *name;
	int (*exec)(const char *me, char *arg);
