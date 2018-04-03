    return NULL == s;
}

#if USE_SSL
static void
parse_https_port_list(https_port_list ** head)
{
    char *token;
    char *t;
    char *host;
    const struct hostent *hp;
    unsigned short port;
    https_port_list *s;
    token = strtok(NULL, w_space);
    if (!token)
	self_destruct();
    host = NULL;
    port = 0;
    if ((t = strchr(token, ':'))) {
	/* host:port */
	host = token;
	*t = '\0';
	port = (unsigned short) atoi(t + 1);
	if (0 == port)
	    self_destruct();
    } else if ((port = atoi(token)) > 0) {
	/* port */
    } else {
	self_destruct();
    }
    s = xcalloc(1, sizeof(*s));
    s->s.sin_port = htons(port);
    if (NULL == host)
	s->s.sin_addr = any_addr;
    else if (1 == safe_inet_addr(host, &s->s.sin_addr))
	(void) 0;
    else if ((hp = gethostbyname(host)))	/* dont use ipcache */
	s->s.sin_addr = inaddrFromHostent(hp);
    else
	self_destruct();
    /* parse options ... */
    while ((token = strtok(NULL, w_space))) {
	if (strncmp(token, "cert=", 5) == 0) {
	    safe_free(s->cert);
	    s->cert = xstrdup(token + 5);
	} else if (strncmp(token, "key=", 4) == 0) {
	    safe_free(s->key);
	    s->key = xstrdup(token + 4);
	} else {
	    self_destruct();
	}
    }
    while (*head)
	head = &(*head)->next;
    *head = s;
}

static void
dump_https_port_list(StoreEntry * e, const char *n, const https_port_list * s)
{
    while (s) {
	storeAppendPrintf(e, "%s %s:%d cert=\"%s\" key=\"%s\"\n",
	    n,
	    inet_ntoa(s->s.sin_addr),
	    ntohs(s->s.sin_port),
	    s->cert,
	    s->key);
	s = s->next;
    }
}

static void
free_https_port_list(https_port_list ** head)
{
    https_port_list *s;
    while ((s = *head) != NULL) {
	*head = s->next;
	safe_free(s->cert);
	safe_free(s->key);
	safe_free(s);
    }
}

#if 0
static int
check_null_https_port_list(const https_port_list * s)
{
    return NULL == s;
}
#endif

#endif /* USE_SSL */

void
configFreeMemory(void)
{
