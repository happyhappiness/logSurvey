    printf("SIZE=30 VALUE=\"%s\"><BR>\n", host);
    printf("<STRONG>Cache Port:</STRONG><INPUT NAME=\"port\" ");
    printf("SIZE=30 VALUE=\"%d\"><BR>\n", port);
    printf("</SELECT><BR>\n");
    printf("<INPUT TYPE=\"submit\" VALUE=\"Continue...\">\n");
    printf("</FORM></PRE>\n");
    print_trailer();
}

static void
error_html(const char *msg)
{
    printf("Content-type: text/html\r\n\r\n");
    printf("<HTML><HEAD><TITLE>Cache Manager Error</TITLE></HEAD>\n");
    printf("<BODY><H1>Cache Manager Error</H1>\n");
    printf("<P>\n%s</P>\n", msg);
    print_trailer();
}

static char *
menu_url(cachemgr_request * req, char *action)
{
    static char url[1024];
    snprintf(url, 1024, "%s?host=%s&port=%d&operation=%s",
	script_name,
	req->hostname,
	req->port,
	action);
    return url;
}

static const char *
munge_menu_line(const char *buf, cachemgr_request * req)
{
    char *x;
    char *a;
    char *d;
    static char html[1024];
    if (strlen(buf) < 1)
	return buf;
    if (*buf != ' ')
	return buf;
    x = xstrdup(buf);
    if ((a = strtok(x, w_space)) == NULL)
	return buf;
    if ((d = strtok(NULL, "")) == NULL)
	return buf;
    snprintf(html, 1024, "<LI><A HREF=\"%s\">%s</A>\n",
	menu_url(req, a), d);
    return html;
}

static int
read_reply(int s, cachemgr_request * req)
{
    char buf[1024];
    FILE *fp = fdopen(s, "r");
    int state = 0;
    int parse_menu = 0;
    if (0 == strlen(req->action))
	parse_menu = 1;
    else if (0 == strcasecmp(req->action, "menu"))
	parse_menu = 1;
    if (fp == NULL) {
	perror("fdopen");
	return 1;
    }
    printf("Content-Type: text/html\r\n\r\n");
    if (parse_menu) {
	printf("<H2>Cache Manager menu for %s:</H2>", req->hostname);
	printf("<UL>\n");
    } else {
	printf("<P><A HREF=\"%s\">%s</A>\n<HR>\n",
	    menu_url(req, "menu"), "Cache Manager menu");
	printf("<PRE>\n");
    }
    while (fgets(buf, 1024, fp) != NULL) {
	if (1 == state)
	    if (parse_menu)
		fputs(munge_menu_line(buf, req), stdout);
	    else
		fputs(buf, stdout);
	if (0 == strcmp(buf, "\r\n"))
	    state++;
    }
    if (parse_menu)
	printf("</UL>\n");
    else
	printf("</PRE>\n");
    print_trailer();
    close(s);
    return 0;
}

static int
process_request(cachemgr_request * req)
{
    const struct hostent *hp;
    static struct sockaddr_in S;
    int s;
    int l;
    static char buf[1024];
    if (req == NULL) {
	noargs_html(CACHEMGR_HOSTNAME, CACHE_HTTP_PORT);
	return 1;
    }
    if (req->hostname == NULL) {
	req->hostname = xstrdup(CACHEMGR_HOSTNAME);
    }
    if (req->port == 0) {
	req->port = CACHE_HTTP_PORT;
    }
    if (req->action == NULL) {
	req->action = xstrdup("");
    }
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
	snprintf(buf, 1024, "socket: %s\n", xstrerror());
	error_html(buf);
	return 1;
    }
    memset(&S, '\0', sizeof(struct sockaddr_in));
    S.sin_family = AF_INET;
    if ((hp = gethostbyname(req->hostname)) != NULL)
	xmemcpy(&S.sin_addr.s_addr, hp->h_addr, hp->h_length);
    else if (safe_inet_addr(req->hostname, &S.sin_addr))
	(void) 0;
    else {
	snprintf(buf, 1024, "Unknown host: %s\n", req->hostname);
	error_html(buf);
	return 1;
    }
    S.sin_port = htons(req->port);
    if (connect(s, (struct sockaddr *) &S, sizeof(struct sockaddr_in)) < 0) {
	snprintf(buf, 1024, "connect: %s\n", xstrerror());
	error_html(buf);
	return 1;
    }
    l = snprintf(buf, 1024,
	"GET cache_object://%s/%s HTTP/1.0\r\n"
	"Accept: */*\r\n"
	"\r\n",
	req->hostname,
	req->action);
    write(s, buf, l);
    return read_reply(s, req);
}

int
main(int argc, char *argv[])
{
    char *s;
    cachemgr_request *req;
    safe_inet_addr("255.255.255.255", &no_addr);
    now = time(NULL);
    if ((s = strrchr(argv[0], '/')))
	progname = xstrdup(s + 1);
    else
	progname = xstrdup(argv[0]);
    if ((s = getenv("SCRIPT_NAME")) != NULL)
	script_name = xstrdup(s);
    req = read_request();
    return process_request(req);
}

static char *
read_post_request(void)
{
    char *s;
    char *buf;
    int len;
    if ((s = getenv("REQUEST_METHOD")) == NULL)
	return NULL;
    if (0 != strcasecmp(s, "POST"))
	return NULL;
    if ((s = getenv("CONTENT_LENGTH")) == NULL)
	return NULL;
    if ((len = atoi(s)) <= 0)
	return NULL;
    buf = xmalloc(len + 1);
    fread(buf, len, 1, stdin);
    buf[len] = '\0';
    return buf;
}

static char *
read_get_request(void)
{
    char *s;
    if ((s = getenv("QUERY_STRING")) == NULL)
	return NULL;
    return xstrdup(s);
}

static cachemgr_request *
read_request(void)
{
    char *buf;
    cachemgr_request *req;
    char *s;
    char *t;
    char *q;
    if ((buf = read_post_request()) != NULL)
	(void) 0;
    else if ((buf = read_get_request()) != NULL)
	(void) 0;
    else
	return NULL;
    if (strlen(buf) == 0)
	return NULL;
    req = xcalloc(1, sizeof(cachemgr_request));
    for (s = strtok(buf, "&"); s != NULL; s = strtok(NULL, "&")) {
	t = xstrdup(s);
	if ((q = strchr(t, '=')) == NULL)
	    continue;
	*q++ = '\0';
	if (0 == strcasecmp(t, "host"))
	    req->hostname = xstrdup(q);
	if (0 == strcasecmp(t, "port"))
	    req->port = atoi(q);
	if (0 == strcasecmp(t, "password"))
	    req->passwd = xstrdup(q);
	if (0 == strcasecmp(t, "operation"))
	    req->action = xstrdup(q);
    }
    return req;
}