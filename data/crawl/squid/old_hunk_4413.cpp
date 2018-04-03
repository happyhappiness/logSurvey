        port = 0;
    }

    s = static_cast<sockaddr_in_list *>(xcalloc(1, sizeof(*s)));
    s->s.sin_port = htons(port);

    if (NULL == host)
        s->s.sin_addr = any_addr;
    else if (1 == safe_inet_addr(host, &s->s.sin_addr))
        (void) 0;
    else if ((hp = gethostbyname(host)))	/* dont use ipcache */
        s->s.sin_addr = inaddrFromHostent(hp);
    else
        self_destruct();

    while (*head)
        head = &(*head)->next;

    *head = s;
}

static void
parse_sockaddr_in_list(sockaddr_in_list ** head)
{
    char *token;

    while ((token = strtok(NULL, w_space))) {
        parse_sockaddr_in_list_token(head, token);
    }
}

static void
dump_sockaddr_in_list(StoreEntry * e, const char *n, const sockaddr_in_list * s)
{
    while (s) {
        storeAppendPrintf(e, "%s %s:%d\n",
                          n,
                          inet_ntoa(s->s.sin_addr),
                          ntohs(s->s.sin_port));
        s = s->next;
    }
}

static void
free_sockaddr_in_list(sockaddr_in_list ** head)
{
    sockaddr_in_list *s;

    while ((s = *head) != NULL) {
        *head = s->next;
        xfree(s);
    }
}

#if CURRENTLY_UNUSED
/* This code was previously used by http_port. Left as it really should
 * be used by icp_port and htcp_port
 */
static int
check_null_sockaddr_in_list(const sockaddr_in_list * s)
{
    return NULL == s;
}
