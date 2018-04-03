
    printf("<HR noshade size=\"1px\">\n");

    printf("<div id=\"Hsmgr\"></div>\n");
    printf("<div id=\"Hmgr\"></div>\n");
    printf("<div id=\"Cmgr\">\n");
    printf("<h2>CGI Managed Proxies</h2>\n");
    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);

    printf("<TABLE BORDER=\"0\" CELLPADDING=\"10\" CELLSPACING=\"1\">\n");


    if (fp != NULL) {
        int servers = 0;
        char config_line[BUFSIZ];
