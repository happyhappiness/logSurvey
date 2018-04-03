			continue;
		}

		if (!dwim_log(argv[i], spec - argv[i], sha1, &ref)) {
			status |= error("no reflog for '%s'", argv[i]);
			continue;
		}

