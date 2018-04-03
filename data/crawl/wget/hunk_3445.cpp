   result = NOCONERROR;
   mynewloc = NULL;
   local_file = NULL;
+  proxy_url = NULL;
 
-  use_proxy = USE_PROXY_P (u);
-  if (use_proxy)
+  proxy = getproxy (u);
+  if (proxy)
     {
-      struct url *proxy_url;
-
-      /* Get the proxy server for the current scheme.  */
-      proxy = getproxy (u->scheme);
-      if (!proxy)
-	{
-	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
-	  url_free (u);
-	  xfree (url);
-	  return PROXERR;
-	}
-
       /* Parse the proxy URL.  */
       proxy_url = url_parse (proxy, &up_error_code);
       if (!proxy_url)
