{
    storeAppendPrintf(&e, "\n\nShared Memory Cache\n");

    storeAppendPrintf(&e, "Maximum Size: %.0f KB\n", Config.memMaxSize/1024.0);

    if (map) {
        const int limit = map->entryLimit();
