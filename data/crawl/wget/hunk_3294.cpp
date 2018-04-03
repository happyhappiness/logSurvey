   /* Host name lookup goes on below. */
 
 #ifdef ENABLE_IPV6
-  {
-    xzero (hints);
-    hints.ai_family   = family;
-    hints.ai_socktype = SOCK_STREAM;
-    if (flags & LH_PASSIVE) 
-      hints.ai_flags = AI_PASSIVE;
-
-    err = getaddrinfo_with_timeout (host, NULL, &hints, &res, opt.dns_timeout);
+  hints.ai_flags = 0;
+  if (flags & LH_PASSIVE) 
+    hints.ai_flags |= AI_PASSIVE;
 
-    if (err != 0 || res == NULL)
-      {
-        if (!(flags & LH_SILENT))
-	  logprintf (LOG_VERBOSE, _("failed: %s.\n"),
-		     err != EAI_SYSTEM ? gai_strerror (err) : strerror (errno));
-        return NULL;
-      }
-    al = address_list_from_addrinfo (res);
-    freeaddrinfo (res);
-  }
+  err = getaddrinfo_with_timeout (host, NULL, &hints, &res, opt.dns_timeout);
+  if (err != 0 || res == NULL)
+    {
+      if (!(flags & LH_SILENT))
+	logprintf (LOG_VERBOSE, _("failed: %s.\n"),
+		   err != EAI_SYSTEM ? gai_strerror (err) : strerror (errno));
+      return NULL;
+    }
+  al = address_list_from_addrinfo (res);
+  freeaddrinfo (res);
 #else
   {
     struct hostent *hptr = gethostbyname_with_timeout (host, opt.dns_timeout);
