}

static void
dump_acl_access(StoreEntry * entry, const char *name, acl_access *head)
{
    acl_list *l;
    while (head != NULL) {
	for (l=head->acl_list; l != NULL; l = l->next) {
	storeAppendPrintf(entry, "%s %s %s%s\n",
		name,
		head->allow ? "Allow" : "Deny",
		l->op ? "" : "!",
		l->acl->name);
        }
	head = head->next;
    }
}

static void
parse_acl_access(acl_access **head)
{
    aclParseAccessLine(head);
}

static void
free_acl_access(acl_access **head)
{
    aclDestroyAccessList(head);
}
