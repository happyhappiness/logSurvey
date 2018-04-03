 	  else
 	    logprintf (LOG_NOTQUIET, _("Proxy %s: Must be HTTP.\n"), proxy);
 	  freeurl (u, 1);
+	  free_slist (redirections);
 	  return PROXERR;
 	}
       u->proto = URLHTTP;
