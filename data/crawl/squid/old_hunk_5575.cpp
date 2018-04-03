	    storeAppendPrintf(entry, "%s %s", name, inet_ntoa(l->addr));
	else
	    storeAppendPrintf(entry, "%s autoselect", name);
	dump_acl_list(entry, l->acl_list);
	storeAppendPrintf(entry, "\n");
    }
}
