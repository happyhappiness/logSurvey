 
       if (opt.enable_iri && (name = idn_decode ((char *) host)) != NULL)
         {
-          int len = strlen (host) + strlen (name) + 4;
-          str = xmalloc (len);
-          snprintf (str, len, "%s (%s)", name, host);
-          str[len-1] = '\0';
-          idn2_free (name);
+          str = aprintf ("%s (%s)", name, host);
+          xfree (name);
         }
 
       logprintf (LOG_VERBOSE, _("Resolving %s... "),
