		 * existing config file.
		 */
		if (git_config_from_file(store_aux, config_filename)) {
			error("invalid config file %s", config_filename);
			free(store.key);
			if (store.value_regex != NULL) {
				regfree(store.value_regex);
