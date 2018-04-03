     else
       hints.ai_family   = PF_UNSPEC;
     hints.ai_socktype = SOCK_STREAM;
-    err = getaddrinfo (host, NULL, &hints, &ai);
+    err = getaddrinfo_with_timeout (host, NULL, &hints, &ai, opt.timeout);
 
     if (err != 0 || ai == NULL)
       {
         if (!silent)
-	  logprintf (LOG_VERBOSE, _("failed: %s.\n"), gai_strerror (err));
+	  logprintf (LOG_VERBOSE, _("failed: %s.\n"),
+		     err != EAI_SYSTEM ? gai_strerror (err) : strerror (errno));
         return NULL;
       }
     al = address_list_from_addrinfo (ai);
