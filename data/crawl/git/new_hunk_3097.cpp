		return 0;
	}

	if (repository_format_precious_objects)
		die(_("cannot prune in a precious-objects repo"));

	while (argc--) {
		unsigned char sha1[20];
		const char *name = *argv++;
