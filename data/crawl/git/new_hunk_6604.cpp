	if (!ret) {
		FILE *f = fopen(path, "w");
		if (!f)
			return error("Could not open %s: %s", path,
				     strerror(errno));
		if (fwrite(result.ptr, result.size, 1, f) != 1)
			error("Could not write %s: %s", path, strerror(errno));
		if (fclose(f))
			return error("Writing %s failed: %s", path,
				     strerror(errno));
	}

	free(cur.ptr);