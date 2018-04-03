				usage(pack_usage);
			continue;
		}
		if (!prefixcmp(arg, "--threads=")) {
			char *end;
			delta_search_threads = strtoul(arg+10, &end, 0);
			if (!arg[10] || *end || delta_search_threads < 1)
				usage(pack_usage);
#ifndef THREADED_DELTA_SEARCH
			if (delta_search_threads > 1)
				warning("no threads support, "
					"ignoring %s", arg);
#endif
			continue;
		}
		if (!prefixcmp(arg, "--depth=")) {
			char *end;
			depth = strtoul(arg+8, &end, 0);