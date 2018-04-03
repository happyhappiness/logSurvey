	}
	trace_argv_printf(argv, argc, "trace: built-in: git");

	status = p->fn(argc, argv, prefix);
	if (status)
		return status;

	/* Somebody closed stdout? */
	if (fstat(fileno(stdout), &st))
		return 0;
	/* Ignore write errors for pipes and sockets.. */
	if (S_ISFIFO(st.st_mode) || S_ISSOCK(st.st_mode))
		return 0;

	/* Check for ENOSPC and EIO errors.. */
	if (ferror(stdout))
		die("write failure on standard output");
	if (fflush(stdout) || fclose(stdout))
		die("write failure on standard output: %s", strerror(errno));

	return 0;
}

static void handle_internal_command(int argc, const char **argv)