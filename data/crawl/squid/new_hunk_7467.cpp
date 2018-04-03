    return size;
}

static char *
describeStatuses(StoreEntry * entry)
{
    LOCAL_ARRAY(char, buf, 256);
    sprintf(buf, "%-13s %-13s %-12s %-12s",
	storeStatusStr[entry->store_status],
	memStatusStr[entry->mem_status],
	swapStatusStr[entry->swap_status],
	pingStatusStr[entry->ping_status]);
    return buf;
}

static char *
describeFlags(StoreEntry * entry)
{
    LOCAL_ARRAY(char, buf, 256);
    int flags = (int) entry->flag;
    char *t;
    buf[0] = '\0';
    if (BIT_TEST(flags, IP_LOOKUP_PENDING))
	strcat(buf, "IP,");
    if (BIT_TEST(flags, DELETE_BEHIND))
	strcat(buf, "DB,");
    if (BIT_TEST(flags, CLIENT_ABORT_REQUEST))
	strcat(buf, "CA,");
    if (BIT_TEST(flags, DELAY_SENDING))
	strcat(buf, "DS,");
    if (BIT_TEST(flags, ABORT_MSG_PENDING))
	strcat(buf, "AP,");
    if (BIT_TEST(flags, RELEASE_REQUEST))
	strcat(buf, "RL,");
    if (BIT_TEST(flags, REFRESH_REQUEST))
	strcat(buf, "RF,");
    if (BIT_TEST(flags, ENTRY_CACHABLE))
	strcat(buf, "EC,");
    if (BIT_TEST(flags, KEY_CHANGE))
	strcat(buf, "KC,");
    if (BIT_TEST(flags, KEY_URL))
	strcat(buf, "KU,");
    if (BIT_TEST(flags, ENTRY_HTML))
	strcat(buf, "HT,");
    if (BIT_TEST(flags, ENTRY_DISPATCHED))
	strcat(buf, "ED,");
    if (BIT_TEST(flags, KEY_PRIVATE))
	strcat(buf, "KP,");
    if (BIT_TEST(flags, HIERARCHICAL))
	strcat(buf, "HI,");
    if (BIT_TEST(flags, ENTRY_NEGCACHED))
	strcat(buf, "NG,");
    if (BIT_TEST(flags, READ_DEFERRED))
	strcat(buf, "RD,");
    if ((t = strrchr(buf, ',')))
	*t = '\0';
    return buf;
}

static char *
describeTimestamps(StoreEntry * entry)
{
    LOCAL_ARRAY(char, buf, 256);
    sprintf(buf, "LV:%-9d LU:%-9d LM:%-9d EX:%-9d",
	(int) entry->timestamp,
	(int) entry->lastref,
	(int) entry->lastmod,
	(int) entry->expires);
    return buf;
}

/* process objects list */
static void
stat_objects_get(cacheinfo * obj, StoreEntry * sentry, int vm_or_not)
{
    StoreEntry *entry = NULL;
    MemObject *mem;
    int N = 0;

    storeAppendPrintf(sentry, open_bracket);

    for (entry = storeGetFirst(); entry != NULL; entry = storeGetNext()) {
	mem = entry->mem_obj;
	if (vm_or_not && mem == NULL)
	    continue;
	if ((++N & 0xFF) == 0) {
	    getCurrentTime();
	    debug(18, 3, "stat_objects_get:  Processed %d objects...\n", N);
	}
	storeAppendPrintf(sentry, "{%s %dL %-25s %s %3d %2d %8d %s}\n",
	    describeStatuses(entry),
	    (int) entry->lock_count,
	    describeFlags(entry),
	    describeTimestamps(entry),
	    (int) entry->refcount,
	    storePendingNClients(entry),
	    mem ? mem->e_current_len : entry->object_len,
	    entry->url);
    }
    storeAppendPrintf(sentry, close_bracket);
}
