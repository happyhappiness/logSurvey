		strcpy(filename + len, fmt_patch_suffix);
	}

	fprintf(realstdout, "%s\n", filename + outdir_offset);
	if (freopen(filename, "w", stdout) == NULL)
		return error("Cannot open patch file %s",filename);

