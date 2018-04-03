	      if (BEGINS_WITH (www_authenticate, "NTLM"))
		ntlm_seen = 1;
	      xfree (pth);
	      xfree (www_authenticate);
	      goto retry_with_auth;
	    }
	}
      request_free (req);
      return AUTHFAILED;
    }
