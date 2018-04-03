    printf("<P>This is a WWW interface to the instrumentation interface\n");
    printf("for the Squid object cache.</P>\n");
    printf("<HR>\n");
    printf("<FORM METHOD=\"GET\" ACTION=\"%s\">\n", script_name);
    printf("<TABLE BORDER=0>\n");
    printf("<TR><TH ALIGN=\"left\">Cache Host:</TH><TD><INPUT NAME=\"host\" ");
    printf("SIZE=30 VALUE=\"%s\"></TD></TR>\n", host);