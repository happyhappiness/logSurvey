	if (depth > 0 && deepen_rev_list)
		die("git upload-pack: deepen and deepen-since (or deepen-not) cannot be used together");
	if (depth > 0)
		deepen(depth, &shallows);
	else if (deepen_rev_list) {
		struct argv_array av = ARGV_ARRAY_INIT;
		int i;
