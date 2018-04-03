    printf("</ADDRESS></BODY></HTML>\n");
}

static void
noargs_html(char *host, int port)
{
    printf("Content-type: text/html\r\n\r\n");
    printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
    printf("<BODY><H1>Cache Manager Interface</H1>\n");
    printf("<P>This is a WWW interface to the instrumentation interface\n");
