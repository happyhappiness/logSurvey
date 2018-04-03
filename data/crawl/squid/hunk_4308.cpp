 #if HAVE_PRCTL && defined(PR_SET_KEEPCAPS) && HAVE_SYS_CAPABILITY_H
 
     if (prctl(PR_SET_KEEPCAPS, 1, 0, 0, 0)) {
-        /* Silent failure unless TPROXY is required. Maybe not started as root */
-#if LINUX_TPROXY2 || LINUX_TPROXY4
-
-        if (need_linux_tproxy)
-            debugs(1, 1, "Error - tproxy support requires capability setting which has failed.  Continuing without tproxy support");
-
-        need_linux_tproxy = 0;
-
-#endif
-
+        IPInterceptor.StopTransparency("capability setting has failed.");
     }
 #endif
 }
