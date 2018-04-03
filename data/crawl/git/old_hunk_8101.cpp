				usage(pack_usage);
			continue;
		}
		if (!prefixcmp(arg, "--depth=")) {
			char *end;
			depth = strtoul(arg+8, &end, 0);