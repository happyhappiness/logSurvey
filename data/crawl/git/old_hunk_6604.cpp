	if (!ret) {
		FILE *f = fopen(path, "w");
		if (!f)
			return error("Could not write to %s", path);
		fwrite(result.ptr, result.size, 1, f);
		fclose(f);
	}

	free(cur.ptr);