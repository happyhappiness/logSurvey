	 * low-level merge driver settings.
	 */
	ret = ll_merge(&result, path, &base, NULL, &cur, "", &other, "", NULL);
	if (ret)
		goto out;

	/*
	 * A successful replay of recorded resolution.
	 * Mark that "postimage" was used to help gc.
	 */
	if (utime(rerere_path(id, "postimage"), NULL) < 0)
		warning("failed utime() on %s: %s",
			rerere_path(id, "postimage"),
			strerror(errno));

	/* Update "path" with the resolution */
	f = fopen(path, "w");
	if (!f)
		return error("Could not open %s: %s", path,
			     strerror(errno));
	if (fwrite(result.ptr, result.size, 1, f) != 1)
		error("Could not write %s: %s", path, strerror(errno));
	if (fclose(f))
		return error("Writing %s failed: %s", path,
			     strerror(errno));

out:
	free(cur.ptr);