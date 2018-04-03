	child.in = -1;
	child.out = -1;
	child.err = 0;
	child.argv = parse_argv(arg, service);

	if (start_command(&child) < 0)
		die("Can't run specified command");
