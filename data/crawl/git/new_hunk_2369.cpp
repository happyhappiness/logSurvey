		print_line(extra);
	parse_credential_file(fn, c, NULL, print_line);
	if (commit_lock_file(&credential_lock) < 0)
		die_errno("unable to write credential store: %s",
			  strerror(errno));
}

static void store_credential_file(const char *fn, struct credential *c)
