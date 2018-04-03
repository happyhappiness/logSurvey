	    CLOSE_INVALIDATE (sock);
	}
      pconn.authorized = 0;
      if (!auth_finished && (user && passwd))
	{
	  /* IIS sends multiple copies of WWW-Authenticate, one with
	     the value "negotiate", and other(s) with data.  Loop over
	     all the occurrences and pick the one we recognize.  */
	  int wapos;
	  const char *wabeg, *waend;
	  char *www_authenticate = NULL;
