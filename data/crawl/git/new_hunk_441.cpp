		return -1;
	}

	if (!handle_dotdot(arg, revs, flags, revarg_opt))
		return 0;

	mark = strstr(arg, "^@");
	if (mark && !mark[2]) {