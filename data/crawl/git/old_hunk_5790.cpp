	int rest = eol - bol;

	if (opt->pre_context || opt->post_context) {
		if (opt->last_shown && lno > opt->last_shown + 1)
			fputs("--\n", stdout);
	}
	opt->last_shown = lno;
