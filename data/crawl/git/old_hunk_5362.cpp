		}
		*eol = ch;
	}
	opt->output(opt, bol, rest);
	opt->output(opt, "\n", 1);
}

