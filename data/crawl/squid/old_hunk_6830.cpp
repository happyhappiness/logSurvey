    wordlist *w;
    wordlist *v;
    while (acl != NULL) {
        v = w = aclDumpGeneric(acl);
	while (v != NULL) {
            storeAppendPrintf(entry, "%s %s %s %s\n",
		    name,
		    acl->name,
		    aclTypeToStr(acl->type),
		    v->key);
	    v = v->next;
	}
	wordlistDestroy(&w);
