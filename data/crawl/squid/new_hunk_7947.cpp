    if ((f = getPidFilename()) == NULL)
	return;
    if ((pid_fp = fopen(f, "w")) == NULL) {
	debug(0, 0, "WARNING: Could not write pid file\n");
	debug(0, 0, "         %s: %s\n", f, xstrerror());
	return;
    }
    fprintf(pid_fp, "%d\n", (int) getpid());
    fclose(pid_fp);