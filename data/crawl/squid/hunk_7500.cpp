     printf("</ADDRESS></BODY></HTML>\n");
 }
 
+
+static void
+print_option(op_t current_opt, op_t opt_nr)
+{
+    printf("<OPTION%sVALUE=\"%s\">%s\n",
+	current_opt == opt_nr ? " SELECTED " : " ",
+	op_cmds[opt_nr],
+	op_cmds_descr[opt_nr]);
+}
+
+
 void
-noargs_html(char *host, int port)
+noargs_html(char *host, int port, char *url)
 {
+    op_t op = INFO;
+
     printf("\r\n\r\n");
     printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
     printf("<BODY><H1>Cache Manager Interface</H1>\n");
-    printf("<p>This is a WWW interface to the instrumentation interface\n");
-    printf("for the Squid object cache.</p>\n");
+    printf("<P>This is a WWW interface to the instrumentation interface\n");
+    printf("for the Squid object cache.</P>\n");
     printf("<HR>\n");
     printf("<PRE>\n");
-    printf("<FORM METHOD=\"POST\" ACTION=\"%s?%s:%d\">\n",
-	script_name, host, port);
+    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
     printf("<STRONG>Cache Host:</STRONG><INPUT NAME=\"host\" ");
-    printf("SIZE=30 VALUE=\"%s\"><BR>\n", CACHEMGR_HOSTNAME);
+    printf("SIZE=30 VALUE=\"%s\"><BR>\n", host);
     printf("<STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
-    printf("SIZE=30 VALUE=\"%d\"><BR>\n", CACHE_HTTP_PORT);
+    printf("SIZE=30 VALUE=\"%d\"><BR>\n", port);
     printf("<STRONG>Password  :</STRONG><INPUT TYPE=\"password\" ");
     printf("NAME=\"password\" SIZE=30 VALUE=\"\"><BR>\n");
     printf("<STRONG>URL       :</STRONG><INPUT NAME=\"url\" ");
-    printf("SIZE=30 VALUE=\"\"><BR>\n");
+    printf("SIZE=30 VALUE=\"%s\"><BR>\n", url);
     printf("<STRONG>Operation :</STRONG>");
     printf("<SELECT NAME=\"operation\">\n");
-    printf("<OPTION SELECTED VALUE=\"info\">Cache Information\n");
-    printf("<OPTION VALUE=\"squid.conf\">Cache Configuration File\n");
-    printf("<OPTION VALUE=\"parameter\">Cache Parameters\n");
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
-    printf("<OPTION VALUE=\"shutdown\">Shutdown Cache (password required)\n");
-    printf("<OPTION VALUE=\"refresh\">Refresh Object (URL required)\n");
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
+    print_option(op, SHUTDOWN);
+    print_option(op, REFRESH);
 #ifdef REMOVE_OBJECT
-    printf("<OPTION VALUE=\"remove\">Remove Object (URL required)\n");
+    print_option(op, REMOVE);
 #endif
     printf("</SELECT><BR>\n");
     printf("<HR>\n");
