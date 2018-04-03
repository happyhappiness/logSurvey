{
    acl_list *l;
    while (head != NULL) {
	for (l = head->acl_list; l != NULL; l = l->next) {
	    storeAppendPrintf(entry, "%s %s %s%s\n",
		name,
		head->allow ? "Allow" : "Deny",
		l->op ? "" : "!",
		l->acl->name);
	}
	head = head->next;
    }
}
