
	fp = fopen(filename, "a");
	if (!fp)
		return error(_("cannot open %s: %s\n"), filename, strerror(errno));

	if (raw_url)
		url = transport_anonymize_url(raw_url);
