		break;
	}

	if (!read_stdin)
		return DIFF_OPT_TST(&opt->diffopt, EXIT_WITH_STATUS)
			&& DIFF_OPT_TST(&opt->diffopt, HAS_CHANGES);

	if (opt->diffopt.detect_rename)
		opt->diffopt.setup |= (DIFF_SETUP_USE_SIZE_CACHE |
				       DIFF_SETUP_USE_CACHE);
	while (fgets(line, sizeof(line), stdin)) {
		unsigned char sha1[20];

		if (get_sha1_hex(line, sha1)) {
			fputs(line, stdout);
			fflush(stdout);
		}
		else
			diff_tree_stdin(line);
	}
	return DIFF_OPT_TST(&opt->diffopt, EXIT_WITH_STATUS)
		&& DIFF_OPT_TST(&opt->diffopt, HAS_CHANGES);
}
