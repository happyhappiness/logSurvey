         }
         if (action == -1) {
             session_logout(detail);
-            printf("%s OK message=\"Bye\"\n", index);
+            printf("%s OK message=\"Bye\"\n", user_key);
         } else if (action == 1) {
             session_login(detail);
-            printf("%s OK message=\"Welcome\"\n", index);
+            printf("%s OK message=\"Welcome\"\n", user_key);
         } else if (session_active(detail)) {
             session_login(detail);
-            printf("%s OK\n", index);
+            printf("%s OK\n", user_key);
         } else if (default_action == 1) {
             session_login(detail);
-            printf("%s ERR message=\"Welcome\"\n", index);
+            printf("%s ERR message=\"Welcome\"\n", user_key);
         } else {
-            printf("%s ERR message=\"No session available\"\n", index);
+            printf("%s ERR message=\"No session available\"\n", user_key);
         }
     }
     shutdown_db();
