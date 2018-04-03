 	  xfree (url);
 	  return PROXERR;
 	}
-      if (proxy_url->scheme != SCHEME_HTTP)
+      if (proxy_url->scheme != SCHEME_HTTP && proxy_url->scheme != u->scheme)
 	{
 	  logprintf (LOG_NOTQUIET, _("Error in proxy URL %s: Must be HTTP.\n"), proxy);
 	  url_free (proxy_url);
 	  xfree (url);
 	  return PROXERR;
 	}
-
-      result = http_loop (u, &mynewloc, &local_file, refurl, dt, proxy_url);
-      url_free (proxy_url);
     }
-  else if (u->scheme == SCHEME_HTTP
+
+  if (u->scheme == SCHEME_HTTP
 #ifdef HAVE_SSL
       || u->scheme == SCHEME_HTTPS
 #endif
-      )
+      || (proxy_url && proxy_url->scheme == SCHEME_HTTP))
     {
-      result = http_loop (u, &mynewloc, &local_file, refurl, dt, NULL);
+      result = http_loop (u, &mynewloc, &local_file, refurl, dt, proxy_url);
     }
   else if (u->scheme == SCHEME_FTP)
     {
