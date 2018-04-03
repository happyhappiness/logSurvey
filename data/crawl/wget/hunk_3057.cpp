   /* No luck with the cache; resolve HOST. */
 
   if (!silent && !numeric_address)
-    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);
+    logprintf (LOG_VERBOSE, _("Resolving %s... "), escnonprint (host));
 
 #ifdef ENABLE_IPV6
   {
