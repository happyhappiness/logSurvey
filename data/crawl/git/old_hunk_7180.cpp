		 * existing config file.
		 */
		if (git_config_from_file(store_aux, config_filename)) {
			fprintf(stderr, "invalid config file\n");
			free(store.key);
			if (store.value_regex != NULL) {
				regfree(store.value_regex);
