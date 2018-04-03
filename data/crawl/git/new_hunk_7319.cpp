		gc_auto_pack_limit = git_config_int(var, value);
		return 0;
	}
	if (!strcmp(var, "gc.pruneexpire")) {
		if (!value)
			return config_error_nonbool(var);
		if (strcmp(value, "now")) {
			unsigned long now = approxidate("now");
			if (approxidate(value) >= now)
				return error("Invalid %s: '%s'", var, value);
		}
		prune_expire = xstrdup(value);
		return 0;
	}
	return git_default_config(var, value);
}

