
		rest = skip_prefix(arg, options->long_name);
		if (!rest) {
			if (strncmp(arg, "no-", 3))
				continue;
			flags |= OPT_UNSET;
			rest = skip_prefix(arg + 3, options->long_name);
			if (!rest)
				continue;
		}
