		free(store.key);

		if ( ENOENT != errno ) {
			error_errno("opening %s", config_filename);
			ret = CONFIG_INVALID_FILE; /* same as "invalid config file" */
			goto out_free;
		}
