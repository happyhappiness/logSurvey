    return size;
}

/* process objects list */
static void
stat_objects_get(cacheinfo * obj, StoreEntry * sentry, int vm_or_not)
{
    LOCAL_ARRAY(char, space, 40);
    LOCAL_ARRAY(char, space2, 40);
    int npend = 0;
    StoreEntry *entry = NULL;
    int N = 0;
    int obj_size;

    storeAppendPrintf(sentry, open_bracket);

    for (entry = storeGetFirst();
	entry != NULL;
	entry = storeGetNext()) {
	if (vm_or_not && (entry->mem_status == NOT_IN_MEMORY) &&
	    (entry->swap_status == SWAP_OK))
	    continue;
	if ((++N & 0xFF) == 0) {
	    getCurrentTime();
	    debug(18, 3, "stat_objects_get:  Processed %d objects...\n", N);
	}
	obj_size = entry->object_len;
	npend = storePendingNClients(entry);
	if (entry->mem_obj)
	    obj_size = entry->mem_obj->e_current_len;
	storeAppendPrintf(sentry, "{ %s %d %s %s %s %s %d %d %s %s }\n",
	    entry->url,
	    obj_size,
	    elapsed_time(entry, (int) entry->timestamp, space),
	    flags_describe(entry),
	    elapsed_time(entry, (int) entry->lastref, space2),
	    ttl_describe(entry),
	    npend,
	    (int) entry->refcount,
	    mem_describe(entry),
	    stat_describe(entry));
    }
    storeAppendPrintf(sentry, close_bracket);
}
