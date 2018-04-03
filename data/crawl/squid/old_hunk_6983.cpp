{
    if (EBIT_TEST(e->flag, RELEASE_REQUEST))
	return;
    if (!storeEntryLocked(e))
	fatal_dump("storeReleaseRequest: unlocked entry");
    debug(20, 3) ("storeReleaseRequest: '%s'\n", storeKeyText(e->key));
    EBIT_SET(e->flag, RELEASE_REQUEST);
    storeSetPrivateKey(e);
