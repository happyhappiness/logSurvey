				symbolic = SHOW_SYMBOLIC_FULL;
				continue;
			}
			if (!strcmp(arg, "--all")) {
				for_each_ref(show_reference, NULL);
				continue;