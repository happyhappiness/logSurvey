         }
         if (err) {
             syslog(LOG_WARNING, "oversized message");
-            goto error;
+            puts("ERR");
+            err = 0;
+            continue;
         }
 
         /*
