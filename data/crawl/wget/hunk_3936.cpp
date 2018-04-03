 	     retrying it.  */
 	failed:
 	  logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
-	  free (authenticate_h);
+	  xfree (authenticate_h);
 	  return AUTHFAILED;
 	}
       else if (!known_authentication_scheme_p (authenticate_h))
 	{
-	  free (authenticate_h);
+	  xfree (authenticate_h);
 	  logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
 	  return AUTHFAILED;
 	}
