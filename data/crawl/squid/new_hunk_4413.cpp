        port = 0;
    }

    if (NULL == host)
        ipa.SetAnyAddr();
    else if ( ipa.GetHostByName(host) )	/* dont use ipcache. Accept either FQDN or IPA. */
        (void) 0;
    else
        self_destruct();

    /* port MUST be set after the IPA lookup/conversion is perofrmed. */
    ipa.SetPort(port);

    while (*head)
        head = &(*head)->next;

    s = static_cast<IPAddress_list *>(xcalloc(1, sizeof(*s)));
    s->s = ipa;

    *head = s;
}

static void
parse_IPAddress_list(IPAddress_list ** head)
{
    char *token;

    while ((token = strtok(NULL, w_space))) {
        parse_IPAddress_list_token(head, token);
    }
}

static void
dump_IPAddress_list(StoreEntry * e, const char *n, const IPAddress_list * s)
{
    char ntoabuf[MAX_IPSTRLEN];

    while (s) {
        storeAppendPrintf(e, "%s %s\n",
                          n,
                          s->s.NtoA(ntoabuf,MAX_IPSTRLEN));
        s = s->next;
    }
}

static void
free_IPAddress_list(IPAddress_list ** head)
{
    if(*head) delete *head; *head = NULL;
}

#if CURRENTLY_UNUSED
/* This code was previously used by http_port. Left as it really should
 * be used by icp_port and htcp_port
 */
static int
check_null_IPAddress_list(const IPAdress_list * s)
{
    return NULL == s;
}
