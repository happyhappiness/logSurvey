
int cmd_remote_ext(int argc, const char **argv, const char *prefix)
{
	if (argc < 3) {
		fprintf(stderr, "Error: URL missing");
		exit(1);
	}

	return command_loop(argv[2]);
}
