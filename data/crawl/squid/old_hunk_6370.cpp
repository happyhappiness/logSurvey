		storeAppendPrintf(entry, "%s %s %s %s%s\n",
		    name, cp->name,
		    head->allow ? "Allow" : "Deny",
		    l->op ? "" : "!",
		    l->acl->name);
	    }
	    head = head->next;
