			strcpy(path, ".merge_file_XXXXXX");
			fd = mkstemp(path);
		} else
			fd = create_file(path, ce->ce_mode);
		if (fd < 0) {
			free(new);
			return error("git-checkout-index: unable to create file %s (%s)",
