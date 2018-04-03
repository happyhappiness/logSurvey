    printf("</ADDRESS></BODY></HTML>\n");
}

void
noargs_html(char *host, int port)
{
    printf("\r\n\r\n");
    printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
    printf("<BODY><H1>Cache Manager Interface</H1>\n");
    printf("<p>This is a WWW interface to the instrumentation interface\n");
    printf("for the Squid object cache.</p>\n");
    printf("<HR>\n");
    printf("<PRE>\n");
    printf("<FORM METHOD=\"POST\" ACTION=\"%s?%s:%d\">\n",
	script_name, host, port);
    printf("<STRONG>Cache Host:</STRONG><INPUT NAME=\"host\" ");
    printf("SIZE=30 VALUE=\"%s\"><BR>\n", CACHEMGR_HOSTNAME);
    printf("<STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
    printf("SIZE=30 VALUE=\"%d\"><BR>\n", CACHE_HTTP_PORT);
    printf("<STRONG>Password  :</STRONG><INPUT TYPE=\"password\" ");
    printf("NAME=\"password\" SIZE=30 VALUE=\"\"><BR>\n");
    printf("<STRONG>URL       :</STRONG><INPUT NAME=\"url\" ");
    printf("SIZE=30 VALUE=\"\"><BR>\n");
    printf("<STRONG>Operation :</STRONG>");
    printf("<SELECT NAME=\"operation\">\n");
    printf("<OPTION SELECTED VALUE=\"info\">Cache Information\n");
    printf("<OPTION VALUE=\"squid.conf\">Cache Configuration File\n");
    printf("<OPTION VALUE=\"parameter\">Cache Parameters\n");
#ifdef MENU_SHOW_LOG
    printf("<OPTION VALUE=\"log\">Cache Log\n");
#endif
    printf("<OPTION VALUE=\"stats/utilization\">Utilization\n");
    printf("<OPTION VALUE=\"stats/io\">I/O\n");
    printf("<OPTION VALUE=\"stats/reply_headers\">HTTP Reply Headers\n");
    printf("<OPTION VALUE=\"stats/filedescriptors\">Filedescriptor Usage\n");
    printf("<OPTION VALUE=\"stats/objects\">Objects\n");
    printf("<OPTION VALUE=\"stats/vm_objects\">VM_Objects\n");
    printf("<OPTION VALUE=\"server_list\">Cache Server List\n");
    printf("<OPTION VALUE=\"stats/ipcache\">IP Cache Contents\n");
    printf("<OPTION VALUE=\"stats/fqdncache\">FQDN Cache Contents\n");
    printf("<OPTION VALUE=\"stats/dns\">DNS Server Statistics\n");
    printf("<OPTION VALUE=\"stats/redirector\">Redirector Statistics\n");
    printf("<OPTION VALUE=\"shutdown\">Shutdown Cache (password required)\n");
    printf("<OPTION VALUE=\"refresh\">Refresh Object (URL required)\n");
#ifdef REMOVE_OBJECT
    printf("<OPTION VALUE=\"remove\">Remove Object (URL required)\n");
#endif
    printf("</SELECT><BR>\n");
    printf("<HR>\n");
