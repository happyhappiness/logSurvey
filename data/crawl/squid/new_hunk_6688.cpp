static void
auth_html(char *host, int port, const char *user_name)
{
    if (!user_name)
	user_name = "";
    if (!host || !strlen(host))
	host = "localhost";
    printf("Content-type: text/html\r\n\r\n");
    printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
    printf("<BODY><H1>Cache Manager Interface</H1>\n");
