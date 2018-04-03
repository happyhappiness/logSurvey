	for (p = argv; *p; p++) {
		if (snprintf(ref, sizeof(ref), "refs/tags/%s", *p)
					>= sizeof(ref)) {
			error(_("tag name too long: %.*s..."), 50, *p);
			had_error = 1;
			continue;
		}
		if (!resolve_ref(ref, sha1, 1, NULL)) {
			error(_("tag '%s' not found."), *p);
			had_error = 1;
			continue;
		}
