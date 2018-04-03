		die(_("--contains option is only allowed with -l."));
	if (filter.points_at.nr)
		die(_("--points-at option is only allowed with -l."));
	if (cmdmode == 'd')
		return for_each_tag_name(argv, delete_tag);
	if (cmdmode == 'v')
