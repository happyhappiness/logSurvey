   if (file)
     *file = NULL;
 
-  u = newurl ();
-  /* Parse the URL. */
-  result = parseurl (url, u, 0);
-  if (result != URLOK)
+  u = url_parse (url, &up_error_code);
+  if (!u)
     {
-      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, uerrmsg (result));
-      freeurl (u, 1);
+      logprintf (LOG_NOTQUIET, "%s: %s.\n", url, url_error (up_error_code));
       if (redirections)
 	string_set_free (redirections);
       xfree (url);
-      return result;
+      return URLERROR;
     }
 
+  if (!refurl)
+    refurl = opt.referer;
+
  redirected:
 
-  /* Set the referer.  */
-  if (refurl)
-    u->referer = xstrdup (refurl);
-  else
-    {
-      if (opt.referer)
-	u->referer = xstrdup (opt.referer);
-      else
-	u->referer = NULL;
-    }
+  result = NOCONERROR;
+  mynewloc = NULL;
+  local_file = NULL;
 
-  local_use_proxy = USE_PROXY_P (u);
-  if (local_use_proxy)
+  use_proxy = USE_PROXY_P (u);
+  if (use_proxy)
     {
-      struct urlinfo *pu = newurl ();
-
-      /* Copy the original URL to new location.  */
-      memcpy (pu, u, sizeof (*u));
-      pu->proxy = NULL; /* A minor correction :) */
-      /* Initialize u to nil.  */
-      memset (u, 0, sizeof (*u));
-      u->proxy = pu;
-      /* Get the appropriate proxy server, appropriate for the
-	 current scheme.  */
-      proxy = getproxy (pu->scheme);
+      struct url *proxy_url;
+
+      /* Get the proxy server for the current scheme.  */
+      proxy = getproxy (u->scheme);
       if (!proxy)
 	{
 	  logputs (LOG_NOTQUIET, _("Could not find proxy host.\n"));
-	  freeurl (u, 1);
+	  url_free (u);
 	  if (redirections)
 	    string_set_free (redirections);
 	  xfree (url);
 	  return PROXERR;
 	}
+
       /* Parse the proxy URL.  */
-      result = parseurl (proxy, u, 0);
-      if (result != URLOK || u->scheme != SCHEME_HTTP)
+      proxy_url = url_parse (proxy, &up_error_code);
+      if (!proxy_url)
 	{
-	  if (u->scheme == SCHEME_HTTP)
-	    logprintf (LOG_NOTQUIET, "Proxy %s: %s.\n", proxy, uerrmsg(result));
-	  else
-	    logprintf (LOG_NOTQUIET, _("Proxy %s: Must be HTTP.\n"), proxy);
-	  freeurl (u, 1);
+	  logprintf (LOG_NOTQUIET, "Error parsing proxy URL %s: %s.\n",
+		     proxy, url_error (up_error_code));
+	  if (redirections)
+	    string_set_free (redirections);
+	  xfree (url);
+	  return PROXERR;
+	}
+      if (proxy_url->scheme != SCHEME_HTTP)
+	{
+	  logprintf (LOG_NOTQUIET, _("Error in proxy URL %s: Must be HTTP.\n"), proxy);
+	  url_free (proxy_url);
 	  if (redirections)
 	    string_set_free (redirections);
 	  xfree (url);
 	  return PROXERR;
 	}
-      u->scheme = SCHEME_HTTP;
-    }
-
-  mynewloc = NULL;
 
-  if (u->scheme == SCHEME_HTTP
+      result = http_loop (u, &mynewloc, &local_file, refurl, dt, proxy_url);
+      url_free (proxy_url);
+    }
+  else if (u->scheme == SCHEME_HTTP
 #ifdef HAVE_SSL
       || u->scheme == SCHEME_HTTPS
 #endif
       )
-    result = http_loop (u, &mynewloc, dt);
+    {
+      result = http_loop (u, &mynewloc, &local_file, refurl, dt, NULL);
+    }
   else if (u->scheme == SCHEME_FTP)
     {
       /* If this is a redirection, we must not allow recursive FTP
