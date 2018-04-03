			apply = 1;
			continue;
		}
		if (!strcmp(arg, "--index-info")) {
			apply = 0;
			show_index_info = 1;
			continue;
		}
		if (!strcmp(arg, "-z")) {
