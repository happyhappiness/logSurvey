			names[i] = argv[i];
		if (read_mmfile(mmfs + i, fname))
			return -1;
		if (mmfs[i].size > MAX_XDIFF_SIZE ||
		    buffer_is_binary(mmfs[i].ptr, mmfs[i].size))
			return error("Cannot merge binary files: %s",
					argv[i]);
	}
