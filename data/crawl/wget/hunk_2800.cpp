 	request_set_header (req, "Proxy-Authorization", proxyauth, rel_value);
     }
 
+  /* Generate the Host header, HOST:PORT.  Take into account that:
+
+     - Broken server-side software often doesn't recognize the PORT
+       argument, so we must generate "Host: www.server.com" instead of
+       "Host: www.server.com:80" (and likewise for https port).
+
+     - IPv6 addresses contain ":", so "Host: 3ffe:8100:200:2::2:1234"
+       becomes ambiguous and needs to be rewritten as "Host:
+       [3ffe:8100:200:2::2]:1234".  */
   {
-    /* Whether we need to print the host header with braces around
-       host, e.g. "Host: [3ffe:8100:200:2::2]:1234" instead of the
-       usual "Host: symbolic-name:1234". */
-    bool squares = strchr (u->host, ':') != NULL;
-    if (u->port == scheme_default_port (u->scheme))
-      request_set_header (req, "Host",
-			  aprintf (squares ? "[%s]" : "%s", u->host),
-			  rel_value);
-    else
-      request_set_header (req, "Host",
-			  aprintf (squares ? "[%s]:%d" : "%s:%d",
-				   u->host, u->port),
-			  rel_value);
+    /* Formats arranged for hfmt[add_port][add_squares].  */
+    static const char *hfmt[][2] = {
+      { "%s", "[%s]" }, { "%s:%d", "[%s]:%d" }
+    };
+    int add_port = u->port != scheme_default_port (u->scheme);
+    int add_squares = strchr (u->host, ':') != NULL;
+    request_set_header (req, "Host",
+			aprintf (hfmt[add_port][add_squares], u->host, u->port),
+			rel_value);
   }
 
   if (!inhibit_keep_alive)
