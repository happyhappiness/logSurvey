         count++;
         hres_list = hres_list->ai_next;
     }
-    rc = xgetnameinfo(hres->ai_addr, hres->ai_addrlen, hostname,
+    rc = getnameinfo(hres->ai_addr, hres->ai_addrlen, hostname,
                       sizeof(hostname), NULL, 0, 0);
     if (rc != 0) {
         fprintf(stderr,
                 "%s| %s: ERROR: resolving ip address with getnameinfo: %s failed\n",
-                LogTime(), PROGRAM, xgai_strerror(rc));
-        xfreeaddrinfo(hres);
+                LogTime(), PROGRAM, gai_strerror(rc));
+        freeaddrinfo(hres);
         return NULL;
     }
 
-    xfreeaddrinfo(hres);
+    freeaddrinfo(hres);
     hostname[sysconf(_SC_HOST_NAME_MAX) - 1] = '\0';
     return (xstrdup(hostname));
 }
