		}
		if (verify)
			die_no_single_rev(quiet);
		as_is = 1;
		if (!show_file(arg, output_prefix))
			continue;
