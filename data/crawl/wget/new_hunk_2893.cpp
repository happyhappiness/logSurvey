	      if (BEGINS_WITH (www_authenticate, "NTLM"))
		ntlm_seen = 1;
	      xfree (pth);
	      goto retry_with_auth;
	    }
	}
      logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
      request_free (req);
      return AUTHFAILED;
    }
