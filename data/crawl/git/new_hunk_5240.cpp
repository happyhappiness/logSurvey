		opt->show_hunk_mark = 1;
	opt->last_shown = 0;

	switch (opt->binary) {
	case GREP_BINARY_DEFAULT:
		if (buffer_is_binary(buf, size))
			binary_match_only = 1;
		break;
	case GREP_BINARY_NOMATCH:
		if (buffer_is_binary(buf, size))
			return 0; /* Assume unmatch */
		break;
	case GREP_BINARY_TEXT:
		break;
	default:
		die("bug: unknown binary handling mode");
	}

	memset(&xecfg, 0, sizeof(xecfg));