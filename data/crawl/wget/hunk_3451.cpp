 	{
 	  logprintf (LOG_NOTQUIET, _("Error in proxy URL %s: Must be HTTP.\n"), proxy);
 	  url_free (proxy_url);
-	  if (redirections)
-	    string_set_free (redirections);
 	  xfree (url);
 	  return PROXERR;
 	}
