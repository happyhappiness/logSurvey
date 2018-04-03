                 }
                 value++;
             }
-            if (show_debug_messages)
-                printf("password: %s\n", password);
+            debug("password: %s\n", password);
             if (password)
                 password = xstrdup(password);
             if (edir_universal_passwd) {
