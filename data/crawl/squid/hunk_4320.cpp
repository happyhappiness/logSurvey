 #if HAVE_PRCTL && defined(PR_SET_KEEPCAPS) && HAVE_SYS_CAPABILITY_H
 
     if (prctl(PR_SET_KEEPCAPS, 1, 0, 0, 0)) {
-        /* Silent failure unless transparency is required. Maybe not started as root */
-        if (IPInterceptor.TransparentActive()) {
-            debugs(1, 1, "Error - full transparency support requires capability setting which has failed. Continuing without transparency support");
-            IPInterceptor.StopTransparency();
-        }
+        IPInterceptor.StopTransparency("capability setting has failed.");
     }
 #endif
 }
