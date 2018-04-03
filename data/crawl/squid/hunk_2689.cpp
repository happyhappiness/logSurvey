         user = strtok(buf, " \r\n");
         passwd = strtok(NULL, "\r\n");
 
-        if (!user || !passwd || !passwd[0]) {
-            printf("ERR\n");
+        if (!user) {
+            printf("ERR Missing username\n");
+            continue;
+        }
+        if (!passwd || !passwd[0]) {
+            printf("ERR Missing password '%s'\n", user);
             continue;
         }
         rfc1738_unescape(user);
         rfc1738_unescape(passwd);
         if (!validUsername(user)) {
-            printf("ERR No such user\n");
+            printf("ERR No such user '%s':'%s'\n",user, passwd);
             continue;
         }
         tryagain = (ld != NULL);