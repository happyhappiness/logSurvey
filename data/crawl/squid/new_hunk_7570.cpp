
    printf("<HTML><HEAD><TITLE>Cache Manager: %s:%s:%d</TITLE></HEAD>\n",
	operation, hostname, portnum);
    printf("<BODY><FORM METHOD=\"POST\" ACTION=\"%s?%s:%d\">\n",
	script_name, query_host, query_port);
    printf("<INPUT TYPE=\"submit\" VALUE=\"Refresh\">\n");
    printf("<SELECT NAME=\"operation\">\n");
    printf("<OPTION SELECTED VALUE=\"%s\">Current\n", operation);
