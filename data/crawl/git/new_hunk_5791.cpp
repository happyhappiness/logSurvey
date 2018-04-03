{
	int rest = eol - bol;

	if (opt->pre_context || opt->post_context) {
		if (opt->last_shown && lno > opt->last_shown + 1)
			fputs("--\n", stdout);
	}
	opt->last_shown = lno;

	if (opt->null_following_name)
		sign = '\0';
	if (opt->pathname)
