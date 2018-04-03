        the addresses with the same family is undisturbed.  */
     if (al->count > 1 && opt.prefer_family != prefer_none)
       stable_sort (al->addresses, al->count, sizeof (ip_address),
-		   opt.prefer_family == prefer_ipv4
-		   ? cmp_prefer_ipv4 : cmp_prefer_ipv6);
+                   opt.prefer_family == prefer_ipv4
+                   ? cmp_prefer_ipv4 : cmp_prefer_ipv6);
   }
 #else  /* not ENABLE_IPV6 */
   {
     struct hostent *hptr = gethostbyname_with_timeout (host, timeout);
     if (!hptr)
       {
-	if (!silent)
-	  {
-	    if (errno != ETIMEDOUT)
-	      logprintf (LOG_VERBOSE, _("failed: %s.\n"),
-			 host_errstr (h_errno));
-	    else
-	      logputs (LOG_VERBOSE, _("failed: timed out.\n"));
-	  }
-	return NULL;
+        if (!silent)
+          {
+            if (errno != ETIMEDOUT)
+              logprintf (LOG_VERBOSE, _("failed: %s.\n"),
+                         host_errstr (h_errno));
+            else
+              logputs (LOG_VERBOSE, _("failed: timed out.\n"));
+          }
+        return NULL;
       }
     /* Do older systems have h_addr_list?  */
     al = address_list_from_ipv4_addresses (hptr->h_addr_list);
