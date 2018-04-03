			argc--;
			argv++;
		}
	}

	if (argc == 4 && !strcmp(argv[1], "longest_ancestor_length")) {
		int len = longest_ancestor_length(argv[2], argv[3]);
		printf("%d\n", len);
	}

	return 0;
}