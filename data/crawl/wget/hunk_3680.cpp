     }
   hs->contlen = contlen;
 
-  /* Return if redirected.  */
-  if (H_REDIRECTED (statcode) || statcode == HTTP_STATUS_MULTIPLE_CHOICES)
-    {
-      /* RFC2068 says that in case of the 300 (multiple choices)
-	 response, the server can output a preferred URL through
-	 `Location' header; otherwise, the request should be treated
-	 like GET.  So, if the location is set, it will be a
-	 redirection; otherwise, just proceed normally.  */
-      if (statcode == HTTP_STATUS_MULTIPLE_CHOICES && !hs->newloc)
-	*dt |= RETROKF;
-      else
-	{
-	  logprintf (LOG_VERBOSE,
-		     _("Location: %s%s\n"),
-		     hs->newloc ? hs->newloc : _("unspecified"),
-		     hs->newloc ? _(" [following]") : "");
-	  CLOSE_INVALIDATE (sock);	/* would be CLOSE_FINISH, but there
-					   might be more bytes in the body. */
-	  FREE_MAYBE (type);
-	  FREE_MAYBE (all_headers);
-	  return NEWLOCATION;
-	}
-    }
   if (opt.verbose)
     {
       if ((*dt & RETROKF) && !opt.server_response)
