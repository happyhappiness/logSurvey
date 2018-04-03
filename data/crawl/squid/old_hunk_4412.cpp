}

static void

dump_address(StoreEntry * entry, const char *name, struct IN_ADDR addr)
{
    storeAppendPrintf(entry, "%s %s\n", name, inet_ntoa(addr));
}

static void

parse_address(struct IN_ADDR *addr)
{

    const struct hostent *hp;
    char *token = strtok(NULL, w_space);

    if (!token) {
        self_destruct();
        return;
    }

    if (safe_inet_addr(token, addr) == 1)
        (void) 0;
    else if ((hp = gethostbyname(token)))	/* dont use ipcache */
        *addr = inaddrFromHostent(hp);
    else
        self_destruct();
}

static void

free_address(struct IN_ADDR *addr)
{

    memset(addr, '\0', sizeof(struct IN_ADDR));
}

CBDATA_TYPE(acl_address);

static void
dump_acl_address(StoreEntry * entry, const char *name, acl_address * head)
{
    acl_address *l;

    for (l = head; l; l = l->next) {
        if (l->addr.s_addr != INADDR_ANY)
            storeAppendPrintf(entry, "%s %s", name, inet_ntoa(l->addr));
        else
            storeAppendPrintf(entry, "%s autoselect", name);

