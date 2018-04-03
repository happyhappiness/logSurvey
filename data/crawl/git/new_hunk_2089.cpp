
	fp = fopen(filename, "a");
	if (!fp)
		return error_errno(_("cannot open %s"), filename);

	if (raw_url)
		url = transport_anonymize_url(raw_url);
