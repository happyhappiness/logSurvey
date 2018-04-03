	}
	else if (0 == strcasecmp (key, "File")) {
		sfree (log_file);

		if ((strcasecmp (value, "stdout") == 0)
				|| (strcasecmp (value, "stderr") == 0)
				|| (access (value, W_OK) == 0))
			log_file = strdup (value);
		else {
			char errbuf[1024];
			/* We can't use `ERROR' yet.. */
			fprintf (stderr, "logfile plugin: Access to %s denied: %s\n",
					value, sstrerror (errno, errbuf, sizeof (errbuf)));
			return 1;
		}
	}
	else {
		return -1;