   *newloc = NULL;
 
   /* Warn on (likely bogus) wildcard usage in HTTP.  Don't use
-     has_wildcards_p because it would also warn on `?', and we that
+     has_wildcards_p because it would also warn on `?', and we know that
      shows up in CGI paths a *lot*.  */
   if (strchr (u->url, '*'))
     logputs (LOG_VERBOSE, _("Warning: wildcards not supported in HTTP.\n"));
