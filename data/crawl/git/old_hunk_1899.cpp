	if (!use_sideband && daemon_mode)
		no_progress = 1;

	if (depth == 0 && shallows.nr == 0)
		return;
	if (depth > 0)
		deepen(depth, &shallows);
	else
		if (shallows.nr > 0) {
			int i;
