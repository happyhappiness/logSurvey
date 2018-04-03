    } else {
	fatal_dump("ipcache_nbgethostbyname: BAD ipcache_entry status");
    }
    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we submit */
    c = xcalloc(1, sizeof(*c));
    c->data = i;
    cbdataAdd(c, MEM_NONE);
    i->status = IP_DISPATCHED;
    ipcacheLockEntry(i);
    dnsSubmit(i->name, ipcacheHandleReply, c);
}

/* initialize the ipcache */
void
ipcache_init(void)
{
    int n;
    debug(14, 3) ("Initializing IP Cache...\n");
    memset(&IpcacheStats, '\0', sizeof(IpcacheStats));
    memset(&lru_list, '\0', sizeof(lru_list));
    /* test naming lookup */
    if (!opt_dns_tests) {
	debug(14, 4) ("ipcache_init: Skipping DNS name lookup tests.\n");
