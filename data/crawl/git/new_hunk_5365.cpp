				break;

			opt->output(opt, bol, match.rm_so);
			output_color(opt, bol + match.rm_so,
				     match.rm_eo - match.rm_so,
				     opt->color_match);
			bol += match.rm_eo;
			rest -= match.rm_eo;
			eflags = REG_NOTBOL;
