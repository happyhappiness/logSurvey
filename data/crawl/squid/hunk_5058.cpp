 static void
 auth_html(const char *host, int port, const char *user_name)
 {
+    FILE *fp;
+    int need_host = 1;
+
     if (!user_name)
         user_name = "";
 
     if (!host || !strlen(host))
-        host = "localhost";
+        host = "";
 
     printf("Content-Type: text/html\r\n\r\n");
 
