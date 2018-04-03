		wt_status_relative_paths = git_config_bool(k, v);
		return 0;
	}
	return git_color_default_config(k, v, cb);
}