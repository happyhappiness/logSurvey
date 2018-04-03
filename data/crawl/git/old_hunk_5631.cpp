	}

	if (argc == 0) {
		describe("HEAD", 1);
	} else {
		while (argc-- > 0) {
			describe(*argv++, argc == 0);
