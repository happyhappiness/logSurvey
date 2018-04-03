   return path_matches (path, cookie_path);
 }
 
-/* Parse the `Set-Cookie' header and, if the cookie is legal, store it
-   to memory.  */
+/* Process the HTTP `Set-Cookie' header.  This results in storing the
+   cookie or discarding a matching one, or ignoring it completely, all
+   depending on the contents.  */
 
-int
-set_cookie_header_cb (const char *hdr, void *closure)
+void
+cookie_jar_process_set_cookie (struct cookie_jar *jar,
+			       const char *host, int port,
+			       const char *path, const char *set_cookie)
 {
-  struct url *u = (struct url *)closure;
   struct cookie *cookie;
-
   cookies_now = time (NULL);
 
-  cookie = parse_set_cookies (hdr);
+  cookie = parse_set_cookies (set_cookie);
   if (!cookie)
     goto out;
 
   /* Sanitize parts of cookie. */
 
   if (!cookie->domain)
-    cookie->domain = xstrdup (u->host);
+    {
+    copy_domain:
+      cookie->domain = xstrdup (host);
+      cookie->port = port;
+    }
   else
     {
-      if (!check_domain_match (cookie->domain, u->host))
+      if (!check_domain_match (cookie->domain, host))
 	{
-	  DEBUGP (("Attempt to fake the domain: %s, %s\n",
-		   cookie->domain, u->host));
-	  goto out;
+	  logprintf (LOG_NOTQUIET,
+		     "Cookie coming from %s attempted to set domain to %s\n",
+		     host, cookie->domain);
+	  goto copy_domain;
 	}
     }
   if (!cookie->path)
-    cookie->path = xstrdup (u->path);
+    cookie->path = xstrdup (path);
   else
     {
-      if (!check_path_match (cookie->path, u->path))
+      if (!check_path_match (cookie->path, path))
 	{
 	  DEBUGP (("Attempt to fake the path: %s, %s\n",
-		   cookie->path, u->path));
+		   cookie->path, path));
 	  goto out;
 	}
     }
 
-  cookie->port = u->port;
-
   if (cookie->discard_requested)
     {
-      discard_matching_cookie (cookie);
+      discard_matching_cookie (jar, cookie);
       delete_cookie (cookie);
-      return 1;
     }
 
-  store_cookie (cookie);
-  return 1;
+  store_cookie (jar, cookie);
+  return;
 
  out:
   if (cookie)
     delete_cookie (cookie);
-  return 1;
 }
 
 /* Support for sending out cookies in HTTP requests, based on
