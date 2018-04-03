	if (depth == 0 && !deepen_rev_list && shallows.nr == 0)
		return;
	if (depth > 0 && deepen_rev_list)
		die("git upload-pack: deepen and deepen-since cannot be used together");
	if (depth > 0)
		deepen(depth, &shallows);
	else if (deepen_rev_list) {
