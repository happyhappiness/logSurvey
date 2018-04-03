		free(store.key);

		if ( ENOENT != errno ) {
			error("opening %s: %s", config_filename,
			      strerror(errno));
			ret = CONFIG_INVALID_FILE; /* same as "invalid config file" */
			goto out_free;
		}
