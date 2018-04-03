 	    printf("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\n");
 	    printf("<HTML><HEAD><TITLE>CacheMgr@%s: %s</TITLE>\n",
 		req->hostname, action);
-	    printf("<STYLE type= \"text/css\"><!--BODY{background-color:#ffffff; font-family:verdana,sans-serif}--></STYLE>\n");
+	    printf("<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff; font-family:verdana,sans-serif}--></STYLE>\n");
 	    printf("</HEAD><BODY>\n");
 	    if (parse_menu) {
 		printf("<H2><a href=\"%s\">Cache Manager</a> menu for %s:</H2>",
