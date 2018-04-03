 	} else {
 	    printf("<P><STRONG>Unknown CGI parameter: %s</STRONG></P>\n",
 		s);
-	    noargs_html(hostname, portnum, url);
+	    noargs_html(hostname, portnum, url, password);
 	    exit(0);
 	}
     }
