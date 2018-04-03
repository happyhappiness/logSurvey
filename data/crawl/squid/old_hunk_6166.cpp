{
    wordlist *w;
    while (list != NULL) {
	storeAppendPrintf(entry, "%s XXXXXXXXXX", name);
	for (w = list->actions; w != NULL; w = w->next) {
	    storeAppendPrintf(entry, " %s", w->key);
	}