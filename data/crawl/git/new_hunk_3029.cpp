	return 0;
}

/*
 * Find the conflict identified by "name"; the change between its
 * "preimage" (i.e. a previous contents with conflict markers) and its
 * "postimage" (i.e. the corresponding contents with conflicts
 * resolved) may apply cleanly to the contents stored in "path", i.e.
 * the conflict this time around.
 *
 * Returns 0 for successful replay of recorded resolution, or non-zero
 * for failure.
 */
static int merge(const char *name, const char *path)
{
	int ret;
	mmfile_t cur = {NULL, 0}, base = {NULL, 0}, other = {NULL, 0};
	mmbuffer_t result = {NULL, 0};

	/*
	 * Normalize the conflicts in path and write it out to
	 * "thisimage" temporary file.
	 */
	if (handle_file(path, NULL, rerere_path(name, "thisimage")) < 0)
		return 1;

	if (read_mmfile(&cur, rerere_path(name, "thisimage")) ||
	    read_mmfile(&base, rerere_path(name, "preimage")) ||
	    read_mmfile(&other, rerere_path(name, "postimage"))) {
		ret = 1;
		goto out;
	}

	/*
	 * A three-way merge. Note that this honors user-customizable
	 * low-level merge driver settings.
	 */
	ret = ll_merge(&result, path, &base, NULL, &cur, "", &other, "", NULL);
	if (!ret) {
		FILE *f;

		/*
		 * A successful replay of recorded resolution.
		 * Mark that "postimage" was used to help gc.
		 */
		if (utime(rerere_path(name, "postimage"), NULL) < 0)
			warning("failed utime() on %s: %s",
					rerere_path(name, "postimage"),
					strerror(errno));

		/* Update "path" with the resolution */
		f = fopen(path, "w");
		if (!f)
			return error("Could not open %s: %s", path,
