					      arg);

		fd = open(arg, O_RDONLY);
		if (fd < 0) {
			error(_("can't open patch '%s': %s"), arg, strerror(errno));
			res = -128;
			goto end;
		}
		read_stdin = 0;
		set_default_whitespace_mode(state);
		res = apply_patch(state, fd, arg, options);
		close(fd);
		if (res < 0)
			goto end;
		errs |= res;
	}
	set_default_whitespace_mode(state);
	if (read_stdin) {
