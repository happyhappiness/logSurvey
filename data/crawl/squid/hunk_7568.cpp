     printf("for the Squid object cache.</p>\n");
     printf("<HR>\n");
     printf("<PRE>\n");
-    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
+    printf("<FORM METHOD=\"POST\" ACTION=\"%s?%s:%d\">\n",
+	script_name, host, port);
     printf("<STRONG>Cache Host:</STRONG><INPUT NAME=\"host\" ");
-    printf("SIZE=30 VALUE=\"%s\">\n\n", CACHEMGR_HOSTNAME);
+    printf("SIZE=30 VALUE=\"%s\">\n\n", host);
     printf("<STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
-    printf("SIZE=30 VALUE=\"%d\">\n\n", CACHE_HTTP_PORT);
+    printf("SIZE=30 VALUE=\"%d\">\n\n", port);
     printf("<STRONG>Password  :</STRONG><INPUT TYPE=\"password\" ");
     printf("NAME=\"password\" SIZE=30 VALUE=\"\">\n\n");
     printf("<STRONG>URL       :</STRONG><INPUT NAME=\"url\" ");
