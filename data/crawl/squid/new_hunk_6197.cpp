    StoreEntry *e = ftpState->entry;
    wordlist *w;
    char *dirup;
    int i, j, k;
    storeBuffer(e);
    storeAppendPrintf(e, "<!-- HTML listing generated by Squid %s -->\n",
	version_string);