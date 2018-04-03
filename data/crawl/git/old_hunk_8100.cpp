		cache_max_small_delta_size = git_config_int(k, v);
		return 0;
	}
	return git_default_config(k, v);
}
