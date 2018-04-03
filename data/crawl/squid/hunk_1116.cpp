             return 1;
         }
 
-    } else {			/* not an auth-request */
+    } else {            /* not an auth-request */
         SEND("BH illegal request received");
         fprintf(stderr, "Illegal request received: '%s'\n", buf);
         return 1;
