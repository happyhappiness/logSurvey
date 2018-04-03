	);
    for (entry = head; entry != NULL; entry = entry->next) {
	assert(entry->name);
	if (entry->loc == NULL) {
	    fprintf(stderr, "NO LOCATION FOR %s\n", entry->name);
	    rc |= 1;
