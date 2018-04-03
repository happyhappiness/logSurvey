    debug(20, 5, "storeRelease: Releasing: %s\n", e->url);

    if (table == (HashID) 0)
	return -1;

    if (e->key == NULL) {
	debug(20, 0, "storeRelease: NULL key for %s\n", e->url);
