	}

	if (!max_candidates)
		die(_("no tag exactly matches '%s'"), sha1_to_hex(cmit->object.sha1));
	if (debug)
		fprintf(stderr, _("searching to describe %s\n"), arg);

	if (!have_util) {
		for_each_hash(&names, set_util);
