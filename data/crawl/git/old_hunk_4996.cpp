			  const unsigned char **replacement)
{
	const unsigned char *repl = lookup_replace_object(sha1);
	void *data = read_object(repl, type, size);
	char *path;
	const struct packed_git *p;

	if (data) {
		if (replacement)
			*replacement = repl;
		return data;
	}

	/* die if we replaced an object with one that does not exist */
	if (repl != sha1)
		die("replacement %s not found for %s",