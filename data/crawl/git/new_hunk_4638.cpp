				char *ref;
				i++;
				if (i >= argc)
					die(_("You need to specify a tag name."));
				ref = xmalloc(strlen(argv[i]) * 2 + 22);
				strcpy(ref, "refs/tags/");
				strcat(ref, argv[i]);
