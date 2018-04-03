    aclDestroyAcls(acl);
}

static void
dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
{
