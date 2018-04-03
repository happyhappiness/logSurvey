 	}
     }
 
-  if (!(flags & LH_SILENT))
-    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);
+  /* No luck with the cache; resolve the host name. */
 
-  /* Host name lookup goes on below. */
+  if (!silent)
+    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);
 
 #ifdef ENABLE_IPV6
   hints.ai_flags = 0;
-  if (flags & LH_PASSIVE) 
-    hints.ai_flags |= AI_PASSIVE;
 
   err = getaddrinfo_with_timeout (host, NULL, &hints, &res, opt.dns_timeout);
   if (err != 0 || res == NULL)
     {
-      if (!(flags & LH_SILENT))
+      if (!silent)
 	logprintf (LOG_VERBOSE, _("failed: %s.\n"),
 		   err != EAI_SYSTEM ? gai_strerror (err) : strerror (errno));
       return NULL;
