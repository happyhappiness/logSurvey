	    printf("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">\n");
	    printf("<HTML><HEAD><TITLE>CacheMgr@%s: %s</TITLE>\n",
		req->hostname, action);
	    printf("<STYLE type=\"text/css\"><!--BODY{background-color:#ffffff;font-family:verdana,sans-serif}PRE{font-family:sans-serif}TABLE{background-color:#333333;border:0pt;padding:0pt}TH,TD{background-color:#ffffff}--></STYLE>\n");
	    printf("</HEAD><BODY>\n");
	    if (parse_menu) {
		printf("<H2><a href=\"%s\">Cache Manager</a> menu for %s:</H2>",
