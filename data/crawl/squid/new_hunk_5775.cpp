}

static void
dump_acl_list(StoreEntry * entry, acl_list * head)
{
    acl_list *l;
    for (l = head; l; l = l->next) {
	storeAppendPrintf(entry, " %s%s",
	    l->op ? null_string : "!",
	    l->acl->name);
    }
}

static void
dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
{
    acl_access *l;
    for (l = head; l; l = l->next) {
	storeAppendPrintf(entry, "%s %s",
	    name,
	    l->allow ? "Allow" : "Deny");
	dump_acl_list(entry, l->acl_list);
	storeAppendPrintf(entry, "\n");
    }
}

