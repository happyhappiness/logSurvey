     }
     if (hostname[0] == '\0') {
 	printf("<H1>ERROR</H1>\n");
-	printf("<P><B>You must provide a hostname!\n</B></P><HR>");
+	printf("<P><STRONG>You must provide a hostname!\n</STRONG></P><HR>");
 	noargs_html();
 	exit(0);
     }
