			die("--bare and --origin %s options are incompatible.",
			    option_origin);
		option_no_checkout = 1;
	}

	if (!option_origin)
