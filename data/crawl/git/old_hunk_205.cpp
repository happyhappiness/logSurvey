	switch (cmdmode) {
	case NEXT_ALL:
		return bisect_next_all(prefix, no_checkout);
	default:
		return error("BUG: unknown subcommand '%d'", cmdmode);
	}
