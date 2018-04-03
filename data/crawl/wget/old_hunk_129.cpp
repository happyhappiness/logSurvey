
      /* pass the parsed values over */
      if (c_max_age)
	{
	  /* If the string value goes out of a long's bounds, strtol() will return LONG_MIN or LONG_MAX.
	   * In theory, the HSTS engine should be able to handle it.
	   * Also, time_t is normally defined as a long, so this should not break.
	   */
	  if (max_age)
	    *max_age = (time_t) strtol (c_max_age, NULL, 10);
	  if (include_subdomains)
	    *include_subdomains = is;

	  DEBUGP (("Parsed Strict-Transport-Security max-age = %s, includeSubDomains = %s\n",
		     c_max_age, (is ? "true" : "false")));

          xfree (c_max_age);
          success = true;
	}
      else
	{
	  /* something weird happened */
	  logprintf (LOG_VERBOSE, "Could not parse String-Transport-Security header\n");
	  success = false;
	}
    }

  return success;
