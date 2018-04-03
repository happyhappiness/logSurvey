		if (option_origin)
			die(_("--bare and --origin %s options are incompatible."),
			    option_origin);
		option_no_checkout = 1;
	}
