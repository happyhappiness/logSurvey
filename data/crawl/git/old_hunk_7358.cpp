			continue;

		rest = skip_prefix(arg, options->long_name);
		if (!rest) {
			/* abbreviated? */
			if (!strncmp(options->long_name, arg, arg_end - arg)) {
