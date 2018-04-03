	      if (*dt & RETROKF)
		{
		  logprintf (LOG_VERBOSE,
			     _("%s (%s) - `%s' saved [%s]\n\n"),
			     tms, tmrate, locf,
			     number_to_static_string (hstat.len));
		  logprintf (LOG_NONVERBOSE,
			     "%s URL:%s [%s] -> \"%s\" [%d]\n",
			     tms, u->url, number_to_static_string (hstat.len),
			     locf, count);
		}
	      ++opt.numurls;
	      total_downloaded_bytes += hstat.len;
