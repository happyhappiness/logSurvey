				return 1;
			if (binary_match_only) {
				opt->output(opt, "Binary file ", 12);
				output_color(opt, name, strlen(name),
					     opt->color_filename);
				opt->output(opt, " matches\n", 9);
				return 1;
			}