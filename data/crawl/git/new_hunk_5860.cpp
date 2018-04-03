
		fd = open(arg, O_RDONLY);
		if (fd < 0)
			die_errno("can't open patch '%s'", arg);
		read_stdin = 0;
		set_default_whitespace_mode(whitespace_option);
		errs |= apply_patch(fd, arg, options);
