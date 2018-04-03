    printf("for the Squid object cache.</P>\n");
    printf("<HR>\n");
    printf("<FORM METHOD=\"GET\" ACTION=\"%s\">\n", script_name);
    printf("<TABLE BORDER=\"0\" CELLPADDING=\"10\" CELLSPACING=\"1\">\n");
    printf("<TR><TH ALIGN=\"left\">Cache Host:</TH><TD><INPUT NAME=\"host\" ");
    printf("SIZE=30 VALUE=\"%s\"></TD></TR>\n", host);
    printf("<TR><TH ALIGN=\"left\">Cache Port:</TH><TD><INPUT NAME=\"port\" ");