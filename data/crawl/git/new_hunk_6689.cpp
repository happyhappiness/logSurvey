		check[i].attr = a;
	}

	for (i = doubledash; i < argc; i++)
		check_attr(cnt, check, argv+1, argv[i]);
	maybe_flush_or_die(stdout, "attribute to stdout");
	return 0;
}