
    printf("<HTML><HEAD><TITLE>Cache Manager: %s:%s:%d</TITLE></HEAD>\n",
	operation, hostname, portnum);
    printf("<BODY><FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
    printf("<INPUT TYPE=\"submit\" VALUE=\"Refresh\">\n");
    printf("<SELECT NAME=\"operation\">\n");
    printf("<OPTION VALUE=\"empty\">Empty Form\n");
    print_option(op, INFO);
    print_option(op, CACHED);
    print_option(op, PARAM);
#ifdef MENU_SHOW_LOG
    print_option(op, LOG);
#endif
    print_option(op, STATS_U);
    print_option(op, STATS_IO);
    print_option(op, STATS_HDRS);
    print_option(op, STATS_FDS);
    print_option(op, STATS_O);
    print_option(op, STATS_VM);
    print_option(op, SERVER);
    print_option(op, STATS_I);
    print_option(op, STATS_F);
    print_option(op, STATS_D);
    print_option(op, STATS_R);
    printf("</SELECT>\n");
    printf("<INPUT TYPE=\"hidden\" NAME=\"host\" VALUE=\"%s\">\n", hostname);
    printf("<INPUT TYPE=\"hidden\" NAME=\"port\" VALUE=\"%d\">\n", portnum);
    printf("<INPUT TYPE=\"hidden\" NAME=\"password\" VALUE=\"NOT_PERMITTED\">\n");
    printf("<INPUT TYPE=\"hidden\" NAME=\"url\" VALUE=\"%s\">\n", url);
    printf("</FORM>\n");
    printf("<HR>\n");

    printf("<H1>%s:  %s:%d</H1>\n", operation, hostname, portnum);
    printf("<P>dated %s</P>\n", time_string);
    printf("<PRE>\n");

    /* Connect to the server */