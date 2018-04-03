					return error("Invalid value for '%s'", k);
			}
		}
	} else if (!strcmp(k, "push.recursesubmodules")) {
		const char *value;
		if (!git_config_get_value("push.recursesubmodules", &value))
			recurse_submodules = parse_push_recurse_submodules_arg(k, value);
	}

	return git_default_config(k, v, NULL);
