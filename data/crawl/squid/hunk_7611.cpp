     printf("<INPUT TYPE=\"hidden\" NAME=\"port\" VALUE=\"%d\">\n", portnum);
     printf("<INPUT TYPE=\"hidden\" NAME=\"password\" VALUE=\"NOT_PERMITTED\">\n");
     printf("</FORM>");
-    printf("<H3><I><A HREF=\"%s\">Empty form</A></H3></I>\n", script_name);
+    printf("<p><em><A HREF=\"%s\">Empty form</A></em></p>\n", script_name);
     printf("<HR>\n");
 
-    printf("<H3>%s:  %s:%d - dated %s</H3><P>", operation,
-	hostname, portnum, time_string);
+    printf("<H1>%s:  %s:%d</H1>\n", operation,
+	hostname, portnum);
+    printf("<p>dated %s</p>\n", time_string);
     printf("<PRE>\n");
 
     /* Connect to the server */
