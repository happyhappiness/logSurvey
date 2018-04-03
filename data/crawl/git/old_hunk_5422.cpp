	return 0;
}

static void verify_remote_names(int nr_heads, const char **heads)
{
	int i;

	for (i = 0; i < nr_heads; i++) {
		const char *local = heads[i];
		const char *remote = strrchr(heads[i], ':');

		if (*local == '+')
			local++;

		/* A matching refspec is okay.  */
		if (remote == local && remote[1] == '\0')
			continue;

		remote = remote ? (remote + 1) : local;
		switch (check_ref_format(remote)) {
		case 0: /* ok */
		case CHECK_REF_FORMAT_ONELEVEL:
			/* ok but a single level -- that is fine for
			 * a match pattern.
			 */
		case CHECK_REF_FORMAT_WILDCARD:
			/* ok but ends with a pattern-match character */
			continue;
		}
		die("remote part of refspec is not a valid name in %s",
		    heads[i]);
	}
}

int cmd_send_pack(int argc, const char **argv, const char *prefix)
{
	int i, nr_refspecs = 0;
