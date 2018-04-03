		revs->edge_hint = 1;
	} else if (!strcmp(arg, "--unpacked")) {
		revs->unpacked = 1;
	} else if (!prefixcmp(arg, "--unpacked=")) {
		die("--unpacked=<packfile> no longer supported.");
	} else if (!strcmp(arg, "-r")) {
		revs->diff = 1;
		DIFF_OPT_SET(&revs->diffopt, RECURSIVE);
