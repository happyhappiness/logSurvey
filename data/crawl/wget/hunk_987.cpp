   proxy = getproxy (u);
   if (proxy)
     {
-      /* sXXXav : support IRI for proxy */
+      /* sXXXav : could a proxy include a path ??? */
+      struct iri *pi = iri_new ();
+      set_uri_encoding (pi, opt.locale);
+      pi->utf8_encode = false;
+
       /* Parse the proxy URL.  */
-      set_ugly_no_encode (true);
-      proxy_url = url_parse (proxy, &up_error_code);
-      set_ugly_no_encode (false);
+      proxy_url = url_parse (proxy, &up_error_code, NULL);
       if (!proxy_url)
         {
           logprintf (LOG_NOTQUIET, _("Error parsing proxy URL %s: %s.\n"),
