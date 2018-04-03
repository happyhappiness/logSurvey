     cap->inheritable = 0;
     cap->effective = (1 << CAP_NET_BIND_SERVICE);
 
-#if LINUX_TPROXY2
-    if (need_linux_tproxy)
-        cap->effective |= (1 << CAP_NET_ADMIN) | (1 << CAP_NET_BROADCAST);
-#elif LINUX_TPROXY4
-    if (need_linux_tproxy)
+    if(IPInterceptor.TransparentActive()) {
         cap->effective |= (1 << CAP_NET_ADMIN);
-
+#if LINUX_TPROXY2
+        cap->effective |= (1 << CAP_NET_BROADCAST);
 #endif
+    }
 
     if (!keep)
         cap->permitted &= cap->effective;
 
     if (capset(head, cap) != 0) {
-        /* Silent failure unless TPROXY is required */
-#if LINUX_TPROXY2 || LINUX_TPROXY4
-
-        if (need_linux_tproxy)
-            debugs(50, 1, "Error enabling needed capabilities. Will continue without tproxy support");
-
-        need_linux_tproxy = 0;
-
-#endif
-
+        IPInterceptor.StopTransparency("Error enabling needed capabilities.");
     }
 
 nocap:
     xfree(head);
     xfree(cap);
-#else /* not defined(_SQUID_LINUX_) && HAVE_SYS_CAPABILITY_H */
-
-#if LINUX_TPROXY2 || LINUX_TPROXY4
-
-    if (need_linux_tproxy)
-        debugs(50, 1, "Missing needed capability support. Will continue without tproxy support");
-
-    need_linux_tproxy = 0;
-#endif
 
+#else /* not defined(_SQUID_LINUX_) && HAVE_SYS_CAPABILITY_H */
+    IPInterceptor.StopTransparency("Missing needed capability support.");
 #endif
 }
 