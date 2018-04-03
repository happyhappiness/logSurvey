{
    if (BIT_TEST(e->flag, RELEASE_REQUEST))
	return;
    if (!storeEntryLocked(e)) {
	debug_trap("Someone called storeReleaseRequest on an unlocked entry");
	debug(20, 0, "  --> '%s'\n", e->url ? e->url : "NULL URL");
	return;
    }
    debug(20, 3, "storeReleaseRequest: FOR '%s'\n", e->key ? e->key : e->url);
    e->flag |= RELEASE_REQUEST;
    storeSetPrivateKey(e);
}

