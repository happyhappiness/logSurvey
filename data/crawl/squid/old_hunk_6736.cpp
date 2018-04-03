}

static void
noargs_html(char *host, int port)
{
    printf("Content-type: text/html\r\n\r\n");
    printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
    printf("<BODY><H1>Cache Manager Interface</H1>\n");
    printf("<P>This is a WWW interface to the instrumentation interface\n");
    printf("for the Squid object cache.</P>\n");
    printf("<HR>\n");
    printf("<PRE>\n");
    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
    printf("<STRONG>Cache Host:</STRONG><INPUT NAME=\"host\" ");
    printf("SIZE=30 VALUE=\"%s\"><BR>\n", host);
    printf("<STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
    printf("SIZE=30 VALUE=\"%d\"><BR>\n", port);
    printf("</SELECT><BR>\n");
    printf("<INPUT TYPE=\"submit\" VALUE=\"Continue...\">\n");
    printf("</FORM></PRE>\n");
    print_trailer();
}

