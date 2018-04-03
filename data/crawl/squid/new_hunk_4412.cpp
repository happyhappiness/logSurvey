}

static void
dump_address(StoreEntry * entry, const char *name, IPAddress &addr)
{
    char buf[MAX_IPSTRLEN];
    storeAppendPrintf(entry, "%s %s\n", name, addr.NtoA(buf,MAX_IPSTRLEN) );
}

static void
parse_address(IPAddress *addr)
{
    char *token = strtok(NULL, w_space);

    if (!token) {
        self_destruct();
        return;
    }

    if (!strcmp(token,"any_addr"))
    {
        addr->SetAnyAddr();
	(void) 0;
    }
    else if ( (!strcmp(token,"no_addr")) || (!strcmp(token,"full_mask")) )
    {
        addr->SetNoAddr();
	(void) 0;
    }
    else
        *addr = token;
}

static void
free_address(IPAddress *addr)
{
    addr->SetEmpty();
}

CBDATA_TYPE(acl_address);

static void
dump_acl_address(StoreEntry * entry, const char *name, acl_address * head)
{
    char buf[MAX_IPSTRLEN];
    acl_address *l;

    for (l = head; l; l = l->next) {
        if (!l->addr.IsAnyAddr())
            storeAppendPrintf(entry, "%s %s", name, l->addr.NtoA(buf,MAX_IPSTRLEN));
        else
            storeAppendPrintf(entry, "%s autoselect", name);

