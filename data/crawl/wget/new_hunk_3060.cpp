	    {
	    failed_tunnel:
	      logprintf (LOG_NOTQUIET, _("Proxy tunneling failed: %s"),
			 message ? escnonprint (message) : "?");
	      xfree_null (message);
	      return CONSSLERR;
	    }
	  xfree_null (message);

	  /* SOCK is now *really* connected to u->host, so update CONN
	     to reflect this.  That way register_persistent will
