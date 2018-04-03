
	return err;
}

void *parse_extra_zip_args(int argc, const char **argv)
{
	for (; argc > 0; argc--, argv++) {
		const char *arg = argv[0];

		if (arg[0] == '-' && isdigit(arg[1]) && arg[2] == '\0')
			zlib_compression_level = arg[1] - '0';
		else
			die("Unknown argument for zip format: %s", arg);
	}
	return NULL;
}
