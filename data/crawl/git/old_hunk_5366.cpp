				return 1;
			if (binary_match_only) {
				opt->output(opt, "Binary file ", 12);
				opt->output(opt, name, strlen(name));
				opt->output(opt, " matches\n", 9);
				return 1;
			}
