		if (errsize)
			regerr = smalloc(errsize);
		/* get error message */
		if (regerror(rcompile, regtemp, regerr, errsize))
			syslog (LOG_ERR, "cannot compile regex %s: %i/%s",
					entry, rcompile, regerr);
		else
			syslog (LOG_ERR, "cannot compile regex %s: %i",
					entry, rcompile);
		if (errsize)
			sfree (regerr);
		regfree (regtemp);
		return (0);
	}
	DBG("regex compiled: %s - %i", entry, rcompile);

