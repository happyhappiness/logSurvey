 
     host[0] = '\0';
 
-    memcpy(&sa, &any_addr, sizeof(sa));
-
-    if (Config.Sockaddr.http && sa.s_addr == any_addr.s_addr)
-        memcpy(&sa, &Config.Sockaddr.http->s.sin_addr, sizeof(sa));
+    if (Config.Sockaddr.http && sa.IsAnyAddr())
+        sa = Config.Sockaddr.http->s;
 
 #if USE_SSL
 
-    if (Config.Sockaddr.https && sa.s_addr == any_addr.s_addr)
-        memcpy(&sa, &Config.Sockaddr.https->http.s.sin_addr, sizeof(sa));
+    if (Config.Sockaddr.https && sa.IsAnyAddr())
+        sa = Config.Sockaddr.https->http.s;
 
 #endif
+
     /*
      * If the first http_port address has a specific address, try a
      * reverse DNS lookup on it.
      */
-    if (sa.s_addr != any_addr.s_addr) {
-        h = gethostbyaddr((char *) &sa,
-                          sizeof(sa), AF_INET);
+    if( !sa.IsAnyAddr() ) {
 
-        if (h != NULL) {
+        sa.GetAddrInfo(AI);
+        /* we are looking for a name. */
+        if(xgetnameinfo(AI->ai_addr, AI->ai_addrlen, host, SQUIDHOSTNAMELEN, NULL, 0, NI_NAMEREQD ) == 0) {
             /* DNS lookup successful */
             /* use the official name from DNS lookup */
-            xstrncpy(host, h->h_name, SQUIDHOSTNAMELEN);
-            debugs(50, 4, "getMyHostname: resolved " << inet_ntoa(sa) << " to '" << host << "'");
+            debugs(50, 4, "getMyHostname: resolved " << sa << " to '" << host << "'");
 
             present = 1;
 
+            sa.FreeAddrInfo(AI);
+
             if (strchr(host, '.'))
                 return host;
-
         }
 
-        debugs(50, 1, "WARNING: failed to resolve " << inet_ntoa(sa) << " to a fully qualified hostname");
+        sa.FreeAddrInfo(AI);
+        debugs(50, 1, "WARNING: failed to resolve " << sa << " to a fully qualified hostname");
     }
+    else {
+        if (gethostname(host, SQUIDHOSTNAMELEN) < 0) {
+            debugs(50, 1, "WARNING: gethostname failed: " << xstrerror());
+        }
+        else {
+            /* Verify that the hostname given resolves properly */
+            struct addrinfo hints;
+            memset(&hints, 0, sizeof(addrinfo));
+            hints.ai_flags = AI_CANONNAME;
+
+            if(xgetaddrinfo(host, NULL, NULL, &AI) == 0) {
+                /* DNS lookup successful */
+                /* use the official name from DNS lookup */
+                debugs(50, 6, "getMyHostname: '" << host << "' resolved into '" << AI->ai_canonname << "'");
+                xstrncpy(host, AI->ai_canonname, SQUIDHOSTNAMELEN);
+                present = 1;
+
+                /* AYJ: do we want to flag AI_ALL and cache the result anywhere. ie as our local host IPs? */
+                if(AI) {
+                    xfreeaddrinfo(AI);
+                    AI = NULL;
+                }
 
-    /*
-     * Get the host name and store it in host to return
-     */
-    if (gethostname(host, SQUIDHOSTNAMELEN) < 0) {
-        debugs(50, 1, "WARNING: gethostname failed: " << xstrerror());
-    } else if ((h = gethostbyname(host)) == NULL) {
-        debugs(50, 1, "WARNING: gethostbyname failed for " << host);
-    } else {
-        debugs(50, 6, "getMyHostname: '" << host << "' resolved into '" << h->h_name << "'");
-        /* DNS lookup successful */
-        /* use the official name from DNS lookup */
-        xstrncpy(host, h->h_name, SQUIDHOSTNAMELEN);
-        present = 1;
-
-        if (strchr(host, '.'))
-            return host;
+                return host;
+            }
+
+            if(AI) xfreeaddrinfo(AI);
+            debugs(50, 1, "WARNING: getaddrinfo('" << host << "') failed: " << xstrerror());
+        }
     }
 
+    /* throw a fatal configuration error when the Host/IP given has bad DNS/rDNS. */
     if (opt_send_signal == -1)
         fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
     else
