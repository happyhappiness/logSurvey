 	  logprintf (LOG_NOTQUIET, _("Error in proxy URL %s: Must be HTTP.\n"), proxy);
 	  url_free (proxy_url);
 	  xfree (url);
+	  RESTORE_POST_DATA;
 	  return PROXERR;
 	}
     }
