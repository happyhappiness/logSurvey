	  if (*dt & RETROKF)
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - `%s' saved [%ld/%ld]\n\n"),
			 tms, tmrate, locf, hstat.len, hstat.contlen);
	      logprintf (LOG_NONVERBOSE,
			 "%s URL:%s [%ld/%ld] -> \"%s\" [%d]\n",
			 tms, u->url, hstat.len, hstat.contlen, locf, count);
	    }
	  ++opt.numurls;
	  total_downloaded_bytes += hstat.len;
