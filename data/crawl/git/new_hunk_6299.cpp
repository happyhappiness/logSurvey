	return for_each_ref_in("refs/bisect/", register_ref, NULL);
}

void read_bisect_paths(void)
{
	struct strbuf str = STRBUF_INIT;
	const char *filename = git_path("BISECT_NAMES");
	FILE *fp = fopen(filename, "r");

	if (!fp)
		die("Could not open file '%s': %s", filename, strerror(errno));

	while (strbuf_getline(&str, fp, '\n') != EOF) {
		char *quoted;
		int res;

		strbuf_trim(&str);
		quoted = strbuf_detach(&str, NULL);
		res = sq_dequote_to_argv(quoted, &rev_argv,
					 &rev_argv_nr, &rev_argv_alloc);
		if (res)
			die("Badly quoted content in file '%s': %s",
			    filename, quoted);
	}

	strbuf_release(&str);
	fclose(fp);
}

static int skipcmp(const void *a, const void *b)
{
	return hashcmp(a, b);
