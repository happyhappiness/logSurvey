	if (count > 1)
		die("--name-only, --name-status, --check and -s are mutually exclusive");

	if (options->find_copies_harder)
		options->detect_rename = DIFF_DETECT_COPY;

	if (options->output_format & (DIFF_FORMAT_NAME |
