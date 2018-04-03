		}
		*eol = ch;
	}
	output_color(opt, bol, rest, line_color);
	opt->output(opt, "\n", 1);
}

