		if (regcomp(key_regexp, key, REG_EXTENDED)) {
			fprintf(stderr, "Invalid key pattern: %s\n", key_);
			free(key);
			goto free_strings;
		}
	} else {
		if (git_config_parse_key(key_, &key, NULL))
			goto free_strings;
	}

	if (regex_) {
