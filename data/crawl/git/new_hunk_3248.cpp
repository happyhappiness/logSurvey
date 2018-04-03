
		key_regexp = (regex_t*)xmalloc(sizeof(regex_t));
		if (regcomp(key_regexp, key, REG_EXTENDED)) {
			error("invalid key pattern: %s", key_);
			free(key_regexp);
			key_regexp = NULL;
			ret = CONFIG_INVALID_PATTERN;
