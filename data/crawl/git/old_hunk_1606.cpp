	if (s->verbose > 1 && s->commitable) {
		/* print_updated() printed a header, so do we */
		if (s->fp != stdout)
			wt_status_print_trailer(s);
		status_printf_ln(s, c, _("Changes to be committed:"));
		rev.diffopt.a_prefix = "c/";
		rev.diffopt.b_prefix = "i/";
