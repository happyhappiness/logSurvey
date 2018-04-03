
	if (option_reference.nr)
		setup_reference();

	fetch_pattern = value.buf;
	refspec = parse_fetch_refspec(1, &fetch_pattern);
