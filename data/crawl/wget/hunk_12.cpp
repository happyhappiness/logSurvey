 
           if (opt.enable_iri && (name = idn_decode ((char *) print)) != NULL)
             {
-              int len = strlen (print) + strlen (name) + 4;
-              str = xmalloc (len);
-              snprintf (str, len, "%s (%s)", name, print);
-              str[len-1] = '\0';
-              idn2_free (name);
+              str = aprintf ("%s (%s)", name, print);
+              xfree (name);
             }
 
           logprintf (LOG_VERBOSE, _("Connecting to %s|%s|:%d... "),
