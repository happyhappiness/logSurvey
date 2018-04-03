			apply = 1;
			continue;
		}
		if (!strcmp(arg, "--build-fake-ancestor")) {
			apply = 0;
			if (++i >= argc)
				die ("need a filename");
			fake_ancestor = argv[i];
			continue;
		}
		if (!strcmp(arg, "-z")) {
