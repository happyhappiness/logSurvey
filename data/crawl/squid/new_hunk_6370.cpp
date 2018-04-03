		storeAppendPrintf(entry, "%s %s %s %s%s\n",
		    name, cp->name,
		    head->allow ? "Allow" : "Deny",
		    l->op ? null_string : "!",
		    l->acl->name);
	    }
	    head = head->next;
