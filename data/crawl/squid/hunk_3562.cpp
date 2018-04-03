 {
     /* NP: keep these two if-endif separate. Non-Linux work perfectly well without Linux syscap support. */
 #if defined(_SQUID_LINUX_)
-
 #if HAVE_SYS_CAPABILITY_H
-#ifndef _LINUX_CAPABILITY_VERSION_1
-#define _LINUX_CAPABILITY_VERSION_1 _LINUX_CAPABILITY_VERSION
-#endif
-    cap_user_header_t head = (cap_user_header_t) xcalloc(1, sizeof(*head));
-    cap_user_data_t cap = (cap_user_data_t) xcalloc(1, sizeof(*cap));
-
-    head->version = _LINUX_CAPABILITY_VERSION_1;
-
-    if (capget(head, cap) != 0) {
-        debugs(50, DBG_IMPORTANT, "Can't get current capabilities");
-    } else if (head->version != _LINUX_CAPABILITY_VERSION_1) {
-        debugs(50, DBG_IMPORTANT, "Invalid capability version " << head->version << " (expected " << _LINUX_CAPABILITY_VERSION_1 << ")");
+    cap_t caps;
+    if (keep)
+        caps = cap_get_proc();
+    else
+        caps = cap_init();
+    if (!caps) {
+        IpInterceptor.StopTransparency("Can't get current capabilities");
     } else {
-
-        head->pid = 0;
-
-        cap->inheritable = 0;
-        cap->effective = (1 << CAP_NET_BIND_SERVICE);
+        int ncaps = 0;
+        int rc = 0;
+        cap_value_t cap_list[10];
+        cap_list[ncaps++] = CAP_NET_BIND_SERVICE;
 
         if (IpInterceptor.TransparentActive()) {
-            cap->effective |= (1 << CAP_NET_ADMIN);
+            cap_list[ncaps++] = CAP_NET_ADMIN;
 #if LINUX_TPROXY2
-            cap->effective |= (1 << CAP_NET_BROADCAST);
+            cap_list[ncaps++] = CAP_NET_BROADCAST;
 #endif
         }
 
-        if (!keep)
-            cap->permitted &= cap->effective;
+        cap_clear_flag(caps, CAP_EFFECTIVE);
+        rc |= cap_set_flag(caps, CAP_EFFECTIVE, ncaps, cap_list, CAP_SET);
+        rc |= cap_set_flag(caps, CAP_PERMITTED, ncaps, cap_list, CAP_SET);
 
-        if (capset(head, cap) != 0) {
+        if (rc || cap_set_proc(caps) != 0) {
             IpInterceptor.StopTransparency("Error enabling needed capabilities.");
         }
+        cap_free(caps);
     }
-
-    xfree(head);
-    xfree(cap);
-
 #else
     IpInterceptor.StopTransparency("Missing needed capability support.");
 #endif /* HAVE_SYS_CAPABILITY_H */
-
-#endif /* !defined(_SQUID_LINUX_) */
+#endif /* _SQUID_LINUX_ */
 }
 
 void *