	    storeAppendPrintf(entry, "%s %s", name, inet_ntoa(l->addr));
	else
	    storeAppendPrintf(entry, "%s autoselect", name);
	dump_acl_list(entry, l->aclList);
	storeAppendPrintf(entry, "\n");
    }
}
