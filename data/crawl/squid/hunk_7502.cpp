 
     printf("<HTML><HEAD><TITLE>Cache Manager: %s:%s:%d</TITLE></HEAD>\n",
 	operation, hostname, portnum);
-    printf("<BODY><FORM METHOD=\"POST\" ACTION=\"%s?%s:%d\">\n",
-	script_name, query_host, query_port);
+    printf("<BODY><FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
     printf("<INPUT TYPE=\"submit\" VALUE=\"Refresh\">\n");
     printf("<SELECT NAME=\"operation\">\n");
-    printf("<OPTION SELECTED VALUE=\"%s\">Current\n", operation);
-    printf("<OPTION VALUE=\"info\">Cache Information\n");
-    printf("<OPTION VALUE=\"squid.conf\">Cache Configuration File\n");
-    printf("<OPTION VALUE=\"parameter\">Cache Parameters\n");
+    printf("<OPTION VALUE=\"empty\">Empty Form\n");
+    print_option(op, INFO);
+    print_option(op, CACHED);
+    print_option(op, PARAM);
 #ifdef MENU_SHOW_LOG
-    printf("<OPTION VALUE=\"log\">Cache Log\n");
-#endif
-    printf("<OPTION VALUE=\"stats/utilization\">Utilization\n");
-    printf("<OPTION VALUE=\"stats/io\">I/O\n");
-    printf("<OPTION VALUE=\"stats/reply_headers\">HTTP Reply Headers\n");
-    printf("<OPTION VALUE=\"stats/filedescriptors\">Filedescriptor Usage\n");
-    printf("<OPTION VALUE=\"stats/objects\">Objects\n");
-    printf("<OPTION VALUE=\"stats/vm_objects\">VM_Objects\n");
-    printf("<OPTION VALUE=\"server_list\">Cache Server List\n");
-    printf("<OPTION VALUE=\"stats/ipcache\">IP Cache Contents\n");
-    printf("<OPTION VALUE=\"stats/fqdncache\">FQDN Cache Contents\n");
-    printf("<OPTION VALUE=\"stats/dns\">DNS Server Statistics\n");
-    printf("<OPTION VALUE=\"stats/redirector\">Redirector Statistics\n");
-    printf("</SELECT>");
+    print_option(op, LOG);
+#endif
+    print_option(op, STATS_U);
+    print_option(op, STATS_IO);
+    print_option(op, STATS_HDRS);
+    print_option(op, STATS_FDS);
+    print_option(op, STATS_O);
+    print_option(op, STATS_VM);
+    print_option(op, SERVER);
+    print_option(op, STATS_I);
+    print_option(op, STATS_F);
+    print_option(op, STATS_D);
+    print_option(op, STATS_R);
+    printf("</SELECT>\n");
     printf("<INPUT TYPE=\"hidden\" NAME=\"host\" VALUE=\"%s\">\n", hostname);
     printf("<INPUT TYPE=\"hidden\" NAME=\"port\" VALUE=\"%d\">\n", portnum);
     printf("<INPUT TYPE=\"hidden\" NAME=\"password\" VALUE=\"NOT_PERMITTED\">\n");
-    printf("</FORM>");
-    printf("<p><em><A HREF=\"%s?%s:%d\">Empty form</A></em></p>\n", script_name,
-	query_host, query_port);
+    printf("<INPUT TYPE=\"hidden\" NAME=\"url\" VALUE=\"%s\">\n", url);
+    printf("</FORM>\n");
     printf("<HR>\n");
 
-    printf("<H1>%s:  %s:%d</H1>\n", operation,
-	hostname, portnum);
-    printf("<p>dated %s</p>\n", time_string);
+    printf("<H1>%s:  %s:%d</H1>\n", operation, hostname, portnum);
+    printf("<P>dated %s</P>\n", time_string);
     printf("<PRE>\n");
 
     /* Connect to the server */