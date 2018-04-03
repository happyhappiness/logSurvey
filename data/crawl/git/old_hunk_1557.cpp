					      arg);

		fd = open(arg, O_RDONLY);
		if (fd < 0)
			die_errno(_("can't open patch '%s'"), arg);
		read_stdin = 0;
		set_default_whitespace_mode(state);
		res = apply_patch(state, fd, arg, options);
		if (res < 0)
			goto end;
		errs |= res;
		close(fd);
	}
	set_default_whitespace_mode(state);
	if (read_stdin) {
