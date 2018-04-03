    wordlist *w;
    wordlist *v;
    while (ae != NULL) {
	v = w = aclDumpGeneric(ae);
	while (v != NULL) {
	    storeAppendPrintf(entry, "%s %s %s %s\n",
		name,
		ae->name,
