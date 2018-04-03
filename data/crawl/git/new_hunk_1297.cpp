	o.branch1 = argv[++i];
	o.branch2 = argv[++i];

	if (get_oid(o.branch1, &h1))
		die("Could not resolve ref '%s'", o.branch1);
	if (get_oid(o.branch2, &h2))
		die("Could not resolve ref '%s'", o.branch2);

	o.branch1 = better_branch_name(o.branch1);
