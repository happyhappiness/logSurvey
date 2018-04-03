    StoreEntry *e = NULL;
    int rm_obj = 0;

    /* Scan row of hash table each second and free storage if we're
     * over the high-water mark */
    storeGetSwapSpace(0);
