	int fd;
};

static int repack_without_ref_fn(const char *refname, const unsigned char *sha1,
				 int flags, void *cb_data)
{
	struct repack_without_ref_sb *data = cb_data;
	char line[PATH_MAX + 100];
	int len;

	if (!strcmp(data->refname, refname))
		return 0;
	len = snprintf(line, sizeof(line), "%s %s\n",
		       sha1_to_hex(sha1), refname);
	/* this should not happen but just being defensive */
	if (len > sizeof(line))
		die("too long a refname '%s'", refname);
	write_or_die(data->fd, line, len);
	return 0;
}
