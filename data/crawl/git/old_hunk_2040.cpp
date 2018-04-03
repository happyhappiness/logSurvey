		error("There were errors while writing %s (%s)",
		      path, strerror(io.io.wrerror));
	if (io.io.output && fclose(io.io.output))
		io.io.wrerror = error("Failed to flush %s: %s",
				      path, strerror(errno));

	if (hunk_no < 0) {
		if (output)
