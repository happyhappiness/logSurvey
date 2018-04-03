}

static void
dump_acl_access(StoreEntry * entry, const char *name, struct _acl_access *head)
{
    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
}

static void
parse_acl_access(struct _acl_access **head)
{
    aclParseAccessLine(head);
}

static void
free_acl_access(struct _acl_access **head)
{
    aclDestroyAccessList(head);
}
