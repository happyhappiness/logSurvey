	{
	  logprintf (LOG_NOTQUIET,
		     "Cookie coming from %s attempted to set domain to %s\n",
		     host, cookie->domain);
	  xfree (cookie->domain);
	  goto copy_domain;
	}
