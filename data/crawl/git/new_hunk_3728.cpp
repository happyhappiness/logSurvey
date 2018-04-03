	}
}

static int check_ignore(struct path_exclude_check *check,
			const char *prefix, const char **pathspec)
{
	const char *path, *full_path;
	char *seen;
	int num_ignored = 0, dtype = DT_UNKNOWN, i;
	struct exclude *exclude;

	if (!pathspec || !*pathspec) {
		if (!quiet)
			fprintf(stderr, "no pathspec given.\n");
		return 0;
	}

	/*
	 * look for pathspecs matching entries in the index, since these
	 * should not be ignored, in order to be consistent with
