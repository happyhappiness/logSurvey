		return 0;

	/* Check for ENOSPC and EIO errors.. */
	if (ferror(stdout))
		die("write failure on standard output");
	if (fflush(stdout) || fclose(stdout))
		die("write failure on standard output: %s", strerror(errno));

	return 0;
}
