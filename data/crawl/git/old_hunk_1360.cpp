		if (!options->file)
			die_errno("Could not open '%s'", path);
		options->close_file = 1;
		return argcount;
	} else
		return 0;
