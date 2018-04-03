
out:
	if (ret) {
		error("unable to update %s: %s", path, strerror(errno));
		if (fp)
			fclose(fp);
		else if (fd >= 0)