}

static void
dump_acl_access(StoreEntry * entry, const char *name, acl_access * head)
{
    acl_list *l;
    while (head != NULL) {
	storeAppendPrintf(entry, "%s %s",
	    name,
	    head->allow ? "Allow" : "Deny");
	for (l = head->acl_list; l != NULL; l = l->next) {
	    storeAppendPrintf(entry, " %s%s",
		l->op ? null_string : "!",
		l->acl->name);
	}
	storeAppendPrintf(entry, "\n");
	head = head->next;
    }
}

