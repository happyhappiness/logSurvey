         auth = passwd_auth(user, passwd);
 #endif
         if (auth == 0) {
-            printf("ERR No such user\n");
+            SEND_ERR("No such user");
         } else {
             if (auth == 2) {
-                printf("ERR Wrong password\n");
+                SEND_ERR("Wrong password");
             } else {
-                printf(OK);
+                SEND_OK("");
             }
         }
     }
-    exit(0);
+    return 0;
 }
