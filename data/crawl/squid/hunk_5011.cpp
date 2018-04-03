             return host;
     }
 
-    fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
+    if (opt_send_signal == -1)
+        fatal("Could not determine fully qualified hostname.  Please set 'visible_hostname'\n");
+    else
+        return ("localhost");
+
     return NULL;		/* keep compiler happy */
 }
 