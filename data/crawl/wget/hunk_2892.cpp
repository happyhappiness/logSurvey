 	       ++wapos)
 	    if (known_authentication_scheme_p (wabeg, waend))
 	      {
-		www_authenticate = strdupdelim (wabeg, waend);
+		BOUNDED_TO_ALLOCA (wabeg, waend, www_authenticate);
 		break;
 	      }
-	  /* If the authentication header is missing or recognized, or
-	     if the authentication scheme is "Basic" (which we send by
-	     default), there's no sense in retrying.  */
-	  if (!www_authenticate
-	      || BEGINS_WITH (www_authenticate, "Basic"))
-	    {
-	      xfree_null (www_authenticate);
-	      logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
-	    }
+
+	  if (!www_authenticate)
+	    /* If the authentication header is missing or
+	       unrecognized, there's no sense in retrying.  */
+	    logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
+	  else if (BEGINS_WITH (www_authenticate, "Basic"))
+	    /* If the authentication scheme is "Basic", which we send
+	       by default, there's no sense in retrying either.  (This
+	       should be changed when we stop sending "Basic" data by
+	       default.)  */
+	    ;
 	  else
 	    {
 	      char *pth;
