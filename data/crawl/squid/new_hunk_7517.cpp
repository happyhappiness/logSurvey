    printf("<FORM METHOD=\"POST\" ACTION=\"%s?%s:%d\">\n",
	script_name, host, port);
    printf("<STRONG>Cache Host:</STRONG><INPUT NAME=\"host\" ");
    printf("SIZE=30 VALUE=\"%s\"><BR>\n", CACHEMGR_HOSTNAME);
    printf("<STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
    printf("SIZE=30 VALUE=\"%d\"><BR>\n", CACHE_HTTP_PORT);
    printf("<STRONG>Password  :</STRONG><INPUT TYPE=\"password\" ");
    printf("NAME=\"password\" SIZE=30 VALUE=\"\"><BR>\n");
    printf("<STRONG>URL       :</STRONG><INPUT NAME=\"url\" ");
    printf("SIZE=30 VALUE=\"\"><BR>\n");
    printf("<STRONG>Operation :</STRONG>");
    printf("<SELECT NAME=\"operation\">\n");
    printf("<OPTION SELECTED VALUE=\"info\">Cache Information\n");
