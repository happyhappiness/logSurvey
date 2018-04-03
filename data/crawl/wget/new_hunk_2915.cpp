    {
      if (!can_validate)
	{
	  logputs (LOG_NOTQUIET,
		   _("Warning: validation of server certificate not possible!\n"));
	  verify = SSL_VERIFY_NONE;
	}
     else
	{
	  /* break handshake if server cert is not valid but allow
	     NO-Cert mode */
	  verify = SSL_VERIFY_PEER;
	}
    }
