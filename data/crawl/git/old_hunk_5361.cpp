		int ch = *eol;
		int eflags = 0;

		*eol = '\0';
		while (next_match(opt, bol, eol, ctx, &match, eflags)) {
			if (match.rm_so == match.rm_eo)
				break;

			opt->output(opt, bol, match.rm_so);
			output_color(opt, bol + match.rm_so,
				     match.rm_eo - match.rm_so,
				     opt->color_match);
