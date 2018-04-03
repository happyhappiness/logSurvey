
out:
	if (ret) {
		error_errno("unable to update %s", path);
		if (fp)
			fclose(fp);
		else if (fd >= 0)