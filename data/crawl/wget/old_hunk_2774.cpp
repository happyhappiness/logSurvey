	      free_hstat (&hstat);
	      continue;
	    }
	  else if (!opt.kill_longer) /* meaning we got more than expected */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - `%s' saved [%s/%s]\n\n"),
			 tms, tmrate, locf,
			 number_to_static_string (hstat.len),
			 number_to_static_string (hstat.contlen));
	      logprintf (LOG_NONVERBOSE,
			 "%s URL:%s [%s/%s] -> \"%s\" [%d]\n",
			 tms, u->url,
			 number_to_static_string (hstat.len),
			 number_to_static_string (hstat.contlen),
			 locf, count);
	      ++opt.numurls;
	      total_downloaded_bytes += hstat.len;

	      /* Remember that we downloaded the file for later ".orig" code. */
	      if (*dt & ADDED_HTML_EXTENSION)
		downloaded_file(FILE_DOWNLOADED_AND_HTML_EXTENSION_ADDED, locf);
	      else
		downloaded_file(FILE_DOWNLOADED_NORMALLY, locf);
	      
	      free_hstat (&hstat);
	      xfree_null (dummy);
	      return RETROK;
	    }
	  else			/* the same, but not accepted */
	    {
	      logprintf (LOG_VERBOSE,
			 _("%s (%s) - Connection closed at byte %s/%s. "),
			 tms, tmrate,
			 number_to_static_string (hstat.len),
			 number_to_static_string (hstat.contlen));
	      printwhat (count, opt.ntry);
	      free_hstat (&hstat);
	      continue;
	    }
	}
      else			/* now hstat.res can only be -1 */
	{
