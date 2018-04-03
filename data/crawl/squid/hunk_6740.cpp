     printf("</ADDRESS></BODY></HTML>\n");
 }
 
-
-static void
-print_option(op_t current_opt, op_t opt_nr)
-{
-    printf("<OPTION%sVALUE=\"%s\">%s\n",
-	current_opt == opt_nr ? " SELECTED " : " ",
-	op_cmds[opt_nr],
-	op_cmds_descr[opt_nr]);
-}
-
-
 static void
-noargs_html(char *host, int port, char *url, char *password)
+noargs_html(char *host, int port)
 {
-    op_t op = INFO;
-
-    printf("\r\n\r\n");
+    printf("Content-type: text/html\r\n\r\n");
     printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
     printf("<BODY><H1>Cache Manager Interface</H1>\n");
     printf("<P>This is a WWW interface to the instrumentation interface\n");
