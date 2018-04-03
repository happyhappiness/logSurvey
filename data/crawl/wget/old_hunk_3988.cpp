	  else
	    logprintf (LOG_NOTQUIET, _("Proxy %s: Must be HTTP.\n"), proxy);
	  freeurl (u, 1);
	  return PROXERR;
	}
      u->proto = URLHTTP;
