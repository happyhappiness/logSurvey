	if (o.verbosity >= 3)
		printf("Merging %s with %s\n", o.branch1, o.branch2);

	failed = merge_recursive_generic(&o, &h1, &h2, bases_count, bases, &result);
	if (failed < 0)
		return 128; /* die() error code */
	return failed;
