		gc_auto_pack_limit = git_config_int(var, value);
		return 0;
	}
	return git_default_config(var, value);
}

