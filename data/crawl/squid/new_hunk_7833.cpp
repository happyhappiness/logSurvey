void noargs_html()
{
    printf("\r\n\r\n");
    printf("<TITLE>Cache Manager Interface</TITLE>\n");
    printf("<H1>Cache Manager Interface</H1>\n");
    printf("<P>\n");
    printf("This is a WWW interface to the instrumentation interface ");
    printf("for the Squid object cache.\n");
    printf("<HR>\n");
    printf("<P>\n");
    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
