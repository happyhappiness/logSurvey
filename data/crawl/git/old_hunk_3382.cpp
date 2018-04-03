				continue;
			}
			if (!strcmp(arg, "--default")) {
				def = argv[i+1];
				i++;
				continue;
			}
			if (!strcmp(arg, "--prefix")) {
				prefix = argv[i+1];
				startup_info->prefix = prefix;
				output_prefix = 1;
				i++;
				continue;
			}
			if (!strcmp(arg, "--revs-only")) {
