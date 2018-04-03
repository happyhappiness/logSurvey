             cap->permitted &= cap->effective;
 
         if (capset(head, cap) != 0) {
-            IPInterceptor.StopTransparency("Error enabling needed capabilities.");
+            IpInterceptor.StopTransparency("Error enabling needed capabilities.");
         }
     }
 
     xfree(head);
     xfree(cap);
 
 #else
-    IPInterceptor.StopTransparency("Missing needed capability support.");
+    IpInterceptor.StopTransparency("Missing needed capability support.");
 #endif /* HAVE_SYS_CAPABILITY_H */
 
 #endif /* !defined(_SQUID_LINUX_) */
