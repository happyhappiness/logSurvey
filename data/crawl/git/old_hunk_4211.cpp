	} else if (!strcmp(name, TRANS_OPT_DEPTH)) {
		if (!value)
			opts->depth = 0;
		else
			opts->depth = atoi(value);
		return 0;
	}
	return 1;