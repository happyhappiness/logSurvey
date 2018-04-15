	}
	else if (0 == strcasecmp (key, "File")) {
		sfree (log_file);
		log_file = strdup (value);
	}
	else {
		return -1;