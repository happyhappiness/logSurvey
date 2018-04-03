	 * Mark that "postimage" was used to help gc.
	 */
	if (utime(rerere_path(id, "postimage"), NULL) < 0)
		warning_errno("failed utime() on %s",
			      rerere_path(id, "postimage"));

	/* Update "path" with the resolution */
	f = fopen(path, "w");
	if (!f)
		return error_errno("Could not open %s", path);
	if (fwrite(result.ptr, result.size, 1, f) != 1)
		error_errno("Could not write %s", path);
	if (fclose(f))
		return error_errno("Writing %s failed", path);

out:
	free(cur.ptr);
