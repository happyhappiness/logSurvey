   bhash = concat_strings (name, ".badhash", (char *)0);
   uname = unique_name (bhash, false);
 
-  logprintf (LOG_VERBOSE, _("Renaming ‘%s’ to ‘%s’.\n"), name, uname);
+  logprintf (LOG_VERBOSE, _("Renaming %s to %s.\n"),
+             quote_n (0, name), quote_n (1, uname));
 
   if (link (name, uname))
     logprintf (LOG_NOTQUIET, "link: %s\n", strerror (errno));
