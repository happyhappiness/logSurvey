         if (!nispasswd) {
             /* User does not exist */
             printf("ERR No such user\n");
+            continue;
+        }
+
 #if HAVE_CRYPT
-        } else if (strcmp(nispasswd, (char *) crypt(passwd, nispasswd)) == 0) {
+        char *crypted = NULL;
+        if ((crypted = crypt(passwd, nispasswd)) && strcmp(nispasswd, crypted) == 0) {
             /* All ok !, thanks... */
             printf("OK\n");
         } else {
             /* Password incorrect */
             printf("ERR Wrong password\n");
-#else
         }
-        else {
-            /* Password incorrect */
-            printf("BH message=\"Missing crypto capability\"\n");
+#else
+        /* Password incorrect */
+        printf("BH message=\"Missing crypto capability\"\n");
 #endif
-        }
     }
     exit(0);
 }