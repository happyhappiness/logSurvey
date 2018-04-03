		if (!options->file)
			die_errno("Could not open '%s'", path);
		options->close_file = 1;
		if (options->use_color != GIT_COLOR_ALWAYS)
			options->use_color = GIT_COLOR_NEVER;
		return argcount;
	} else
		return 0;
