	return lock_ref_sha1_basic(refname, old_sha1, flags, NULL);
}

/*
 * Write an entry to the packed-refs file for the specified refname.
 * If peeled is non-NULL, write it as the entry's peeled value.
 */
static void write_packed_entry(int fd, char *refname, unsigned char *sha1,
			       unsigned char *peeled)
{
	char line[PATH_MAX + 100];
	int len;

	len = snprintf(line, sizeof(line), "%s %s\n",
		       sha1_to_hex(sha1), refname);
	/* this should not happen but just being defensive */
	if (len > sizeof(line))
		die("too long a refname '%s'", refname);
	write_or_die(fd, line, len);

	if (peeled) {
		if (snprintf(line, sizeof(line), "^%s\n",
			     sha1_to_hex(peeled)) != PEELED_LINE_LENGTH)
			die("internal error");
		write_or_die(fd, line, PEELED_LINE_LENGTH);
	}
}

static int repack_ref_fn(struct ref_entry *entry, void *cb_data)
{
	int *fd = cb_data;
	enum peel_status peel_status;

	if (entry->flag & REF_ISBROKEN) {
		/* This shouldn't happen to packed refs. */
		error("%s is broken!", entry->name);
