{
    wordlist *w;
    while (list != NULL) {
	if (strcmp(list->passwd, "none") && strcmp(list->passwd, "disable"))
	    storeAppendPrintf(entry, "%s XXXXXXXXXX", name);
	else
	    storeAppendPrintf(entry, "%s %s", name, list->passwd);
	for (w = list->actions; w != NULL; w = w->next) {
	    storeAppendPrintf(entry, " %s", w->key);
	}