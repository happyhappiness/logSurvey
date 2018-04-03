     printf("<ADDRESS>\n");
     printf("Generated %s, by %s/%s@%s\n",
 	tbuf, progname, SQUID_VERSION, getfullhostname());
-    printf("</ADDRESS>\n");
+    printf("</ADDRESS></BODY></HTML>\n");
 }
 
 void noargs_html()
 {
     printf("\r\n\r\n");
-    printf("<TITLE>Cache Manager Interface</TITLE>\n");
-    printf("<H1>Cache Manager Interface</H1>\n");
-    printf("<P>\n");
-    printf("This is a WWW interface to the instrumentation interface ");
-    printf("for the Squid object cache.\n");
+    printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
+    printf("<BODY><H1>Cache Manager Interface</H1>\n");
+    printf("<p>This is a WWW interface to the instrumentation interface\n");
+    printf("for the Squid object cache.</p>\n");
     printf("<HR>\n");
-    printf("<P>\n");
-    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
     printf("<PRE>\n");
-    printf("<BR><STRONG>Cache Host:</STRONG><INPUT NAME=\"host\" ");
-    printf("SIZE=30 VALUE=\"%s\">\n", CACHEMGR_HOSTNAME);
-    printf("<BR><STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
-    printf("SIZE=30 VALUE=\"%d\">\n", CACHE_HTTP_PORT);
-    printf("<BR><STRONG>Password  :</STRONG><INPUT TYPE=\"password\" ");
-    printf("NAME=\"password\" SIZE=30 VALUE=\"\">\n");
-    printf("<BR><STRONG>URL       :</STRONG><INPUT NAME=\"url\" ");
-    printf("SIZE=30 VALUE=\"\">\n");
-    printf("<BR><STRONG>Operation :</STRONG>");
+    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
+    printf("<STRONG>Cache Host:</STRONG><INPUT NAME=\"host\" ");
+    printf("SIZE=30 VALUE=\"%s\">\n\n", CACHEMGR_HOSTNAME);
+    printf("<STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
+    printf("SIZE=30 VALUE=\"%d\">\n\n", CACHE_HTTP_PORT);
+    printf("<STRONG>Password  :</STRONG><INPUT TYPE=\"password\" ");
+    printf("NAME=\"password\" SIZE=30 VALUE=\"\">\n\n");
+    printf("<STRONG>URL       :</STRONG><INPUT NAME=\"url\" ");
+    printf("SIZE=30 VALUE=\"\">\n\n");
+    printf("<STRONG>Operation :</STRONG>");
     printf("<SELECT NAME=\"operation\">\n");
     printf("<OPTION SELECTED VALUE=\"info\">Cache Information\n");
     printf("<OPTION VALUE=\"squid.conf\">Cache Configuration File\n");
