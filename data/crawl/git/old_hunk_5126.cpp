	}
	ret = ll_merge(&result, path, &base, NULL, &cur, "", &other, "", 0);
	if (!ret) {
		FILE *f = fopen(path, "w");
		if (!f)
			return error("Could not open %s: %s", path,
				     strerror(errno));
