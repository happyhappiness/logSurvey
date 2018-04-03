     {
       /* Authorization is required.  */
       if (keep_alive && !head_only && skip_short_body (sock, contlen))
-	CLOSE_FINISH (sock);
+        CLOSE_FINISH (sock);
       else
-	CLOSE_INVALIDATE (sock);
+        CLOSE_INVALIDATE (sock);
       pconn.authorized = false;
       if (!auth_finished && (user && passwd))
-	{
-	  /* IIS sends multiple copies of WWW-Authenticate, one with
-	     the value "negotiate", and other(s) with data.  Loop over
-	     all the occurrences and pick the one we recognize.  */
-	  int wapos;
-	  const char *wabeg, *waend;
-	  char *www_authenticate = NULL;
-	  for (wapos = 0;
-	       (wapos = resp_header_locate (resp, "WWW-Authenticate", wapos,
-					    &wabeg, &waend)) != -1;
-	       ++wapos)
-	    if (known_authentication_scheme_p (wabeg, waend))
-	      {
-		BOUNDED_TO_ALLOCA (wabeg, waend, www_authenticate);
-		break;
-	      }
-
-	  if (!www_authenticate)
-	    /* If the authentication header is missing or
-	       unrecognized, there's no sense in retrying.  */
-	    logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
-	  else if (BEGINS_WITH (www_authenticate, "Basic"))
-	    /* If the authentication scheme is "Basic", which we send
-	       by default, there's no sense in retrying either.  (This
-	       should be changed when we stop sending "Basic" data by
-	       default.)  */
-	    ;
-	  else
-	    {
-	      char *pth;
-	      pth = url_full_path (u);
-	      request_set_header (req, "Authorization",
-				  create_authorization_line (www_authenticate,
-							     user, passwd,
-							     request_method (req),
-							     pth,
-							     &auth_finished),
-				  rel_value);
-	      if (BEGINS_WITH (www_authenticate, "NTLM"))
-		ntlm_seen = true;
-	      xfree (pth);
-	      goto retry_with_auth;
-	    }
-	}
+        {
+          /* IIS sends multiple copies of WWW-Authenticate, one with
+             the value "negotiate", and other(s) with data.  Loop over
+             all the occurrences and pick the one we recognize.  */
+          int wapos;
+          const char *wabeg, *waend;
+          char *www_authenticate = NULL;
+          for (wapos = 0;
+               (wapos = resp_header_locate (resp, "WWW-Authenticate", wapos,
+                                            &wabeg, &waend)) != -1;
+               ++wapos)
+            if (known_authentication_scheme_p (wabeg, waend))
+              {
+                BOUNDED_TO_ALLOCA (wabeg, waend, www_authenticate);
+                break;
+              }
+
+          if (!www_authenticate)
+            /* If the authentication header is missing or
+               unrecognized, there's no sense in retrying.  */
+            logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
+          else if (BEGINS_WITH (www_authenticate, "Basic"))
+            /* If the authentication scheme is "Basic", which we send
+               by default, there's no sense in retrying either.  (This
+               should be changed when we stop sending "Basic" data by
+               default.)  */
+            ;
+          else
+            {
+              char *pth;
+              pth = url_full_path (u);
+              request_set_header (req, "Authorization",
+                                  create_authorization_line (www_authenticate,
+                                                             user, passwd,
+                                                             request_method (req),
+                                                             pth,
+                                                             &auth_finished),
+                                  rel_value);
+              if (BEGINS_WITH (www_authenticate, "NTLM"))
+                ntlm_seen = true;
+              xfree (pth);
+              goto retry_with_auth;
+            }
+        }
       logputs (LOG_NOTQUIET, _("Authorization failed.\n"));
       request_free (req);
       return AUTHFAILED;
