

static void
dump_denyinfo(StoreEntry * entry, const char *name, acl_deny_info_list *var)
{
    storeAppendPrintf(entry, "%s -- UNIMPLEMENTED\n", name);
}

static void
parse_denyinfo(acl_deny_info_list **var)
{
    aclParseDenyInfoLine(var);
}
