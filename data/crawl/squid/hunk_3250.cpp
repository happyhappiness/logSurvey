         }
 
     } else {			/* not an auth-request */
-        helperfail("illegal request received");
+        SEND("BH illegal request received");
         fprintf(stderr, "Illegal request received: '%s'\n", buf);
         return 1;
     }
-    helperfail("detected protocol error");
+    SEND("BH detected protocol error");
     return 1;
     /********* END ********/
 }
