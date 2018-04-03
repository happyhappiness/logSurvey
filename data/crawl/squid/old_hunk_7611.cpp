    printf("<INPUT TYPE=\"hidden\" NAME=\"port\" VALUE=\"%d\">\n", portnum);
    printf("<INPUT TYPE=\"hidden\" NAME=\"password\" VALUE=\"NOT_PERMITTED\">\n");
    printf("</FORM>");
    printf("<H3><I><A HREF=\"%s\">Empty form</A></H3></I>\n", script_name);
    printf("<HR>\n");

    printf("<H3>%s:  %s:%d - dated %s</H3><P>", operation,
	hostname, portnum, time_string);
    printf("<PRE>\n");

    /* Connect to the server */
