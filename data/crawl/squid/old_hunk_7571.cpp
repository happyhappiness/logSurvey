    printf("<INPUT TYPE=\"hidden\" NAME=\"port\" VALUE=\"%d\">\n", portnum);
    printf("<INPUT TYPE=\"hidden\" NAME=\"password\" VALUE=\"NOT_PERMITTED\">\n");
    printf("</FORM>");
    printf("<p><em><A HREF=\"%s\">Empty form</A></em></p>\n", script_name);
    printf("<HR>\n");

    printf("<H1>%s:  %s:%d</H1>\n", operation,