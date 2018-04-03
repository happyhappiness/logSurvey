    for (l = head; l; l = l->next) {
	storeAppendPrintf(entry, " %s%s",
	    l->op ? null_string : "!",
	    l->_acl->name);
    }
}

