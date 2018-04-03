					return error("Invalid value for '%s'", k);
			}
		}
	}

	return git_default_config(k, v, NULL);
