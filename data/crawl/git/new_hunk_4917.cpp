		if (parse_one_feature(a + 2, 0))
			continue;

		if (!prefixcmp(a + 2, "cat-blob-fd=")) {
			option_cat_blob_fd(a + 2 + strlen("cat-blob-fd="));
			continue;
		}

		die("unknown option %s", a);
	}
	if (i != global_argc)
