	       ++wapos)
	    if (known_authentication_scheme_p (wabeg, waend))
	      {
		www_authenticate = strdupdelim (wabeg, waend);
		break;
	      }
	  /* If the authentication header is missing or recognized, or
	     if the authentication scheme is "Basic" (which we send by
	     default), there's no sense in retrying.  */
	  if (!www_authenticate
	      || BEGINS_WITH (www_authenticate, "Basic"))
	    {
	      xfree_null (www_authenticate);
	      logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
	    }
	  else
	    {
	      char *pth;
