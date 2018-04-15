		if (errsize)
			regerr = smalloc(errsize);
		/* get error message */
		if (regerror (rcompile, regtemp, regerr, errsize))
		{
			fprintf (stderr, "Cannot compile regex %s: %i/%s",
					entry, rcompile, regerr);
			syslog (LOG_ERR, "Cannot compile regex %s: %i/%s",
					entry, rcompile, regerr);
		}
		else
		{
			fprintf (stderr, "Cannot compile regex %s: %i",
					entry, rcompile);
			syslog (LOG_ERR, "Cannot compile regex %s: %i",
					entry, rcompile);
		}

		if (errsize)
			sfree (regerr);
		regfree (regtemp);
		return (1);
	}
	DBG("regex compiled: %s - %i", entry, rcompile);

