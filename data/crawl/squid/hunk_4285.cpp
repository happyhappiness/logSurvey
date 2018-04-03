     printf("<HTML><HEAD><TITLE>Cache Manager Error</TITLE>\n");
     printf("<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff;font-family:verdana,sans-serif}--></STYLE></HEAD>\n");
     printf("<BODY><H1>Cache Manager Error</H1>\n");
-    printf("<P>\n%s</P>\n", msg);
+    printf("<P>\n%s</P>\n", html_quote(msg));
     print_trailer();
 }
 
