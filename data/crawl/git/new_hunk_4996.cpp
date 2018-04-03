			  const unsigned char **replacement)
{
	const unsigned char *repl = lookup_replace_object(sha1);
	void *data;
	char *path;
	const struct packed_git *p;

	errno = 0;
	data = read_object(repl, type, size);
	if (data) {
		if (replacement)
			*replacement = repl;
		return data;
	}

	if (errno != ENOENT)
		die_errno("failed to read object %s", sha1_to_hex(sha1));

	/* die if we replaced an object with one that does not exist */
	if (repl != sha1)
		die("replacement %s not found for %s",