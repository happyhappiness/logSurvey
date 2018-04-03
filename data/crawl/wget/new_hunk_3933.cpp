	     what you accept."  Oh boy.  */
	  logputs (LOG_VERBOSE, "\n");
	  logputs (LOG_NOTQUIET, _("End of file while parsing headers.\n"));
	  xfree (hdr);
	  FREE_MAYBE (type);
	  FREE_MAYBE (hs->newloc);
	  FREE_MAYBE (all_headers);
