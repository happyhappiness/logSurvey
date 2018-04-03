
			if (!cmd_diff_index(ARRAY_SIZE(diff_index_args) - 1,
					    diff_index_args, prefix))
				suffix = NULL;
			else
				suffix = dirty;
		}
		describe("HEAD", 1);
	} else if (dirty) {
		die(_("--dirty is incompatible with commit-ishes"));
	} else if (broken) {
		die(_("--broken is incompatible with commit-ishes"));
	} else {
		while (argc-- > 0)
			describe(*argv++, argc == 0);
