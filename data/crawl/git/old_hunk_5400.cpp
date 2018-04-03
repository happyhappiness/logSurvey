	    !(prefix = strip_path_suffix(argv0_path, BINDIR)) &&
	    !(prefix = strip_path_suffix(argv0_path, "git"))) {
		prefix = PREFIX;
		fprintf(stderr, "RUNTIME_PREFIX requested, "
				"but prefix computation failed.  "
				"Using static fallback '%s'.\n", prefix);
	}