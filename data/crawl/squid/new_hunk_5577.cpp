	while (head != NULL) {
	    storeAppendPrintf(entry, "%s %ld %s", name, (long int) bs->maxsize,
		head->allow ? "Allow" : "Deny");
	    for (l = head->aclList; l != NULL; l = l->next) {
		storeAppendPrintf(entry, " %s%s",
		    l->op ? null_string : "!",
		    l->_acl->name);
	    }
	    storeAppendPrintf(entry, "\n");
	    head = head->next;
