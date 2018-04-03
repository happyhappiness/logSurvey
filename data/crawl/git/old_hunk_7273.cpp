			if (!strcmp(argv[i], "tag")) {
				char *ref;
				i++;
				ref = xmalloc(strlen(argv[i]) * 2 + 22);
				strcpy(ref, "refs/tags/");
				strcat(ref, argv[i]);