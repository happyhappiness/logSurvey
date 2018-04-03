    time_val = time(NULL);
    time_string = ctime(&time_val);

    printf("<TITLE>Cache Manager: %s:%s:%d</TITLE>\n", operation, hostname, portnum);
    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
    printf("<INPUT TYPE=\"submit\" VALUE=\"Refresh\">\n");
    printf("<SELECT NAME=\"operation\">\n");
    printf("<OPTION SELECTED VALUE=\"%s\">Current\n", operation);
