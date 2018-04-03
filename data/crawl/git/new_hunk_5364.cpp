		      const char *name, unsigned lno, char sign)
{
	int rest = eol - bol;

	if (opt->pre_context || opt->post_context) {
		if (opt->last_shown == 0) {
			if (opt->show_hunk_mark) {
				output_color(opt, "--", 2, opt->color_sep);
				opt->output(opt, "\n", 1);
			} else
				opt->show_hunk_mark = 1;
		} else if (lno > opt->last_shown + 1) {
			output_color(opt, "--", 2, opt->color_sep);
			opt->output(opt, "\n", 1);
		}
	}
	opt->last_shown = lno;

	if (opt->pathname) {
		output_color(opt, name, strlen(name), opt->color_filename);
		output_sep(opt, sign);
	}
	if (opt->linenum) {
		char buf[32];
		snprintf(buf, sizeof(buf), "%d", lno);
		output_color(opt, buf, strlen(buf), opt->color_lineno);
		output_sep(opt, sign);
	}
	if (opt->color) {
		regmatch_t match;
