	return 0;
}

static int write_error(void)
{
	fprintf(stderr, "Failed to write new configuration file\n");

	/* Same error code as "failed to rename". */
	return 4;
