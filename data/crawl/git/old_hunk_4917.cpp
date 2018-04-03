		if (parse_one_feature(a + 2, 0))
			continue;

		die("unknown option %s", a);
	}
	if (i != global_argc)
