	FILE *fp = fopen(filename, "w");

	if (!fp)
		return error("cannot open %s: %s\n", filename, strerror(errno));
	fclose(fp);
	return 0;
}
