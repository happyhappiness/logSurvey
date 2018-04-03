
	if (option_reference.nr)
		setup_reference();
	else if (option_dissociate) {
		warning(_("--dissociate given, but there is no --reference"));
		option_dissociate = 0;
	}

	fetch_pattern = value.buf;
	refspec = parse_fetch_refspec(1, &fetch_pattern);
