	 */
	if (opt->count && count) {
		char buf[32];
		output_color(opt, gs->name, strlen(gs->name), opt->color_filename);
		output_sep(opt, ':');
		snprintf(buf, sizeof(buf), "%u\n", count);
		opt->output(opt, buf, strlen(buf));
