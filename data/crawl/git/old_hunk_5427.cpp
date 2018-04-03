		pack_compression_seen = 1;
		return 0;
	}
	if (!strcmp(k, "core.bigfilethreshold")) {
		long n = git_config_int(k, v);
		big_file_threshold = 0 < n ? n : 0;