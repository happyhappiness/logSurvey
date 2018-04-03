	if (opt->line_level_traverse)
		return line_log_print(opt, commit);

	shown = log_tree_diff(opt, commit, &log);
	if (!shown && opt->loginfo && opt->always_show_header) {
		log.parent = NULL;
		show_log(opt);
		shown = 1;
	}
	opt->loginfo = NULL;
	maybe_flush_or_die(stdout, "stdout");
	return shown;
