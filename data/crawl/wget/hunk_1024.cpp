   /* No luck with the cache; resolve HOST. */
 
   if (!silent && !numeric_address)
-    logprintf (LOG_VERBOSE, _("Resolving %s... "), 
-               quotearg_style (escape_quoting_style, host));
+    {
+      char *str = NULL, *name = NULL;
+
+      if (opt.enable_iri && (name = idn_decode (host)) != NULL)
+        {
+          int len = strlen (host) + strlen (name) + 4;
+          str = xmalloc (len);
+          snprintf (str, len, "%s (%s)", name, host);
+          str[len-1] = '\0';
+          xfree (name);
+        }
+
+      logprintf (LOG_VERBOSE, _("Resolving %s... "), 
+                 quotearg_style (escape_quoting_style, str ? str : host));
+
+      if (str)
+        xfree (str);
+    }
 
 #ifdef ENABLE_IPV6
   {
