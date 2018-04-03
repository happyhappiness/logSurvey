    cachemgrRegister("ipcache",
	"IP Cache Stats and Contents",
	stat_ipcache_get, 0, 1);
    memDataInit(MEM_IPCACHE_ENTRY, "ipcache_entry", sizeof(ipcache_entry), 0);
}

const ipcache_addrs *
ipcache_gethostbyname(const char *name, int flags)
{
    ipcache_entry *i = NULL;
    ipcache_addrs *addrs;
    assert(name);
    debug(14, 3) ("ipcache_gethostbyname: '%s', flags=%x\n", name, flags);
    IpcacheStats.requests++;
    i = ipcache_get(name);
    if (NULL == i) {
	(void) 0;
    } else if (ipcacheExpiredEntry(i)) {
	ipcacheRelease(i);
	i = NULL;
    } else if (i->flags.negcached) {
	IpcacheStats.negative_hits++;
	dns_error_message = i->error_message;
	return NULL;
    } else {
	IpcacheStats.hits++;
	i->lastref = squid_curtime;
	return &i->addrs;
    }
    if ((addrs = ipcacheCheckNumeric(name)))
	return addrs;
