			i++;
			break;
		}
		if (arg[0] == '-') {
			if (extra_argc > MAX_EXTRA_ARGS - 1)
				die("Too many extra options");
			extra_argv[extra_argc++] = arg;
			continue;
		}
		break;
	}

