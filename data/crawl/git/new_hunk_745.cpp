		die(_("-n option is only allowed in list mode"));
	if (filter.with_commit)
		die(_("--contains option is only allowed in list mode"));
	if (filter.no_commit)
		die(_("--no-contains option is only allowed in list mode"));
	if (filter.points_at.nr)
		die(_("--points-at option is only allowed in list mode"));
	if (filter.merge_commit)
