                 }
                 value++;
             }
-            if (show_debug_messages)
-                printf("password: %s\n", password);
+            debug("password: %s\n", password);
             if (password)
                 password = xstrdup(password);
             ldap_value_free(values);
