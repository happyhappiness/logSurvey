		      const char *name, unsigned lno, char sign)
{
	int rest = eol - bol;
	char sign_str[1];

	sign_str[0] = sign;
	if (opt->pre_context || opt->post_context) {
		if (opt->last_shown == 0) {
			if (opt->show_hunk_mark)
				opt->output(opt, "--\n", 3);
			else
				opt->show_hunk_mark = 1;
		} else if (lno > opt->last_shown + 1)
			opt->output(opt, "--\n", 3);
	}
	opt->last_shown = lno;

	if (opt->null_following_name)
		sign_str[0] = '\0';
	if (opt->pathname) {
		opt->output(opt, name, strlen(name));
		opt->output(opt, sign_str, 1);
	}
	if (opt->linenum) {
		char buf[32];
		snprintf(buf, sizeof(buf), "%d", lno);
		opt->output(opt, buf, strlen(buf));
		opt->output(opt, sign_str, 1);
	}
	if (opt->color) {
		regmatch_t match;
