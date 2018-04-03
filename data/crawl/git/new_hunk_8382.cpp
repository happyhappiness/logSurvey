			argp = stdin_only;
	}

	while (*argp) {
		const char *arg = *argp++;
		struct stat argstat;
		int ret = 0;

		if (arg[0] == '-' && arg[1] == 0) {
			ret = split_mbox(arg, dir, allow_bare, nr_prec, nr);
			if (ret < 0) {
				error("cannot split patches from stdin");
				return 1;
			}
			num += ret;
			continue;
		}

		if (stat(arg, &argstat) == -1) {
			error("cannot stat %s (%s)", arg, strerror(errno));
			return 1;
		}

		if (S_ISDIR(argstat.st_mode))
			ret = split_maildir(arg, dir, nr_prec, nr);
		else
			ret = split_mbox(arg, dir, allow_bare, nr_prec, nr);

		if (ret < 0) {
			error("cannot split patches from %s", arg);
			return 1;
		}
		num += ret;
	}

	printf("%d\n", num);

	return 0;
}
