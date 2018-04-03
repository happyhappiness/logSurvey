extern int _dns_ttl_;
#endif

static void
ipcacheEnqueue(ipcache_entry * i)
{
    static time_t last_warning = 0;
    struct ipcacheQueueData *new = xcalloc(1, sizeof(struct ipcacheQueueData));
    new->i = i;
    *ipcacheQueueTailP = new;
    ipcacheQueueTailP = &new->next;
    queue_length++;
    if (queue_length < NDnsServersAlloc)
	return;
    if (squid_curtime - last_warning < 600)
	return;
    last_warning = squid_curtime;
    debug(14, 0) ("ipcacheEnqueue: WARNING: All dnsservers are busy.\n");
    debug(14, 0) ("ipcacheEnqueue: WARNING: %d DNS lookups queued\n", queue_length);
    if (queue_length > NDnsServersAlloc * 2)
	fatal("Too many queued DNS lookups");
    if (Config.dnsChildren >= DefaultDnsChildrenMax)
	return;
    debug(14, 1) ("ipcacheEnqueue: Consider increasing 'dns_children' in your config file.\n");
}

static void *
ipcacheDequeue(void)
{
    struct ipcacheQueueData *old = NULL;
    ipcache_entry *i = NULL;
    if (ipcacheQueueHead) {
	i = ipcacheQueueHead->i;
	old = ipcacheQueueHead;
	ipcacheQueueHead = ipcacheQueueHead->next;
	if (ipcacheQueueHead == NULL)
	    ipcacheQueueTailP = &ipcacheQueueHead;
	safe_free(old);
	queue_length--;
    }
    if (i != NULL)
	assert(i->status == IP_PENDING);
    return i;
}

static int
ipcache_testname(void)
{
