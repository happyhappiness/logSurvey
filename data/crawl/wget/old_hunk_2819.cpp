		{
		  if (contlen >= 1024)
		    logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
			       with_thousand_seps (contlen),
			       human_readable (contlen));
		  else
		    logprintf (LOG_VERBOSE, _(", %s remaining"),
			       with_thousand_seps (contlen));
		}
	    }
	  else
