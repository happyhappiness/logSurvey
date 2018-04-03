           str = xmalloc (len);
           snprintf (str, len, "%s (%s)", name, host);
           str[len-1] = '\0';
-          idn_free (name);
+          idn2_free (name);
         }
 
       logprintf (LOG_VERBOSE, _("Resolving %s... "),
