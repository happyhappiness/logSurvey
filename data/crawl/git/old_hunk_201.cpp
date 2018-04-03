		if (argc != 2)
			return error(_("--write-terms requires two arguments"));
		return write_terms(argv[0], argv[1]);
	default:
		return error("BUG: unknown subcommand '%d'", cmdmode);
	}
