	store_hash_buckets, storeKeyHashHash);
    storeDigestInit();
    storeLogOpen();
    store_list.head = store_list.tail = NULL;
    inmem_list.head = inmem_list.tail = NULL;
    stackInit(&LateReleaseStack);
    eventAdd("storeLateRelease", storeLateRelease, NULL, 1.0, 1);
    storeDirInit();
    cachemgrRegister("storedir",
	"Store Directory Stats",
	storeDirStats, 0, 1);
