}

static void
auth_html(char *host, int port, const char *user_name)
{
    if (!user_name)
	user_name = "";
    printf("Content-type: text/html\r\n\r\n");
    printf("<HTML><HEAD><TITLE>Cache Manager Interface</TITLE></HEAD>\n");
    printf("<BODY><H1>Cache Manager Interface</H1>\n");
    printf("<P>This is a WWW interface to the instrumentation interface\n");
    printf("for the Squid object cache.</P>\n");
    printf("<HR>\n");
    printf("<FORM METHOD=\"POST\" ACTION=\"%s\">\n", script_name);
    printf("<TABLE BORDER=0>\n");
    printf("<TR><TH ALIGN=\"left\">Cache Host:</TH><TD><INPUT NAME=\"host\" ");
    printf("SIZE=30 VALUE=\"%s\"></TD></TR>\n", host ? host : "localhost");
    printf("<TR><TH ALIGN=\"left\">Cache Port:</TH><TD><INPUT NAME=\"port\" ");
    printf("SIZE=30 VALUE=\"%d\"></TD></TR>\n", port);
    printf("<TR><TH ALIGN=\"left\">Manager name:</TH><TD><INPUT NAME=\"user_name\" ");
    printf("SIZE=30 VALUE=\"%s\"></TD></TR>\n", user_name);
    printf("<TR><TH ALIGN=\"left\">Password:</TH><TD><INPUT TYPE=\"password\" NAME=\"passwd\" ");
    printf("SIZE=30 VALUE=\"\"></TD></TR>\n");
    printf("</TABLE><BR CLEAR=\"all\">\n");
    printf("<INPUT TYPE=\"submit\" VALUE=\"Continue...\">\n");
    printf("</FORM>\n");
    print_trailer();
}

