		check[i].attr = a;
	}

	for (i = doubledash; i < argc; i++) {
		int j;
		if (git_checkattr(argv[i], cnt, check))
			die("git_checkattr died");
		for (j = 0; j < cnt; j++) {
			const char *value = check[j].value;

			if (ATTR_TRUE(value))
				value = "set";
			else if (ATTR_FALSE(value))
				value = "unset";
			else if (ATTR_UNSET(value))
				value = "unspecified";

			quote_c_style(argv[i], NULL, stdout, 0);
			printf(": %s: %s\n", argv[j+1], value);
		}
	}
	return 0;
}