{
    if (e->flag & RELEASE_REQUEST)
	return;
    if (!storeEntryLocked(e))
	fatal_dump("Somebody called storeReleaseRequest on an unlocked entry");
    debug(20, 3, "storeReleaseRequest: FOR '%s'\n", e->key ? e->key : e->url);
    e->flag |= RELEASE_REQUEST;
}
