{
    if (e->flag & RELEASE_REQUEST)
	return;
    if (!storeEntryLocked(e)) {
	debug_trap("Somebody called storeReleaseRequest on an unlocked entry");
	return;
    }
    debug(20, 3, "storeReleaseRequest: FOR '%s'\n", e->key ? e->key : e->url);
    e->flag |= RELEASE_REQUEST;
}
