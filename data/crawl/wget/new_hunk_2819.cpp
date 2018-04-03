		{
		  if (contlen >= 1024)
		    logprintf (LOG_VERBOSE, _(", %s (%s) remaining"),
			       number_to_static_string (contlen),
			       human_readable (contlen));
		  else
		    logprintf (LOG_VERBOSE, _(", %s remaining"),
			       number_to_static_string (contlen));
		}
	    }
	  else
