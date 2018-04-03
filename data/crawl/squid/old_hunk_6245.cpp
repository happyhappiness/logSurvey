static long fqdncache_low = 180;
static long fqdncache_high = 200;

static void
fqdncacheEnqueue(fqdncache_entry * f)
{
    static time_t last_warning = 0;
    struct fqdncacheQueueData *new = xcalloc(1, sizeof(struct fqdncacheQueueData));
    new->f = f;
    *fqdncacheQueueTailP = new;
    fqdncacheQueueTailP = &new->next;
    queue_length++;
    if (queue_length < NDnsServersAlloc)
	return;
    if (squid_curtime - last_warning < 600)
	return;
    last_warning = squid_curtime;
    debug(35, 0) ("fqdncacheEnqueue: WARNING: All dnsservers are busy.\n");
    debug(35, 0) ("fqdncacheEnqueue: WARNING: %d DNS lookups queued\n", queue_length);
    if (queue_length > NDnsServersAlloc * 2)
	fatal("Too many queued DNS lookups");
    if (Config.dnsChildren >= DefaultDnsChildrenMax)
	return;
    debug(35, 1) ("fqdncacheEnqueue: Consider increasing 'dns_children' in your config file.\n");
}

static void *
fqdncacheDequeue(void)
{
    struct fqdncacheQueueData *old = NULL;
    fqdncache_entry *f = NULL;
    if (fqdncacheQueueHead) {
	f = fqdncacheQueueHead->f;
	old = fqdncacheQueueHead;
	fqdncacheQueueHead = fqdncacheQueueHead->next;
	if (fqdncacheQueueHead == NULL)
	    fqdncacheQueueTailP = &fqdncacheQueueHead;
	safe_free(old);
	queue_length--;
    }
    if (f && f->status != FQDN_PENDING)
	debug_trap("fqdncacheDequeue: status != FQDN_PENDING");
    return f;
}

/* removes the given fqdncache entry */
static void
fqdncache_release(fqdncache_entry * f)
