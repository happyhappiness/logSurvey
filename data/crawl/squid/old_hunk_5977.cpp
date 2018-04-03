ipcacheStatPrint(ipcache_entry * i, StoreEntry * sentry)
{
    int k;
    storeAppendPrintf(sentry, " %-32.32s  %c%c %6d %6d %2d(%2d)",
	i->name,
	ipcache_status_char[i->status],
	i->locks ? 'L' : ' ',
	(int) (squid_curtime - i->lastref),
	(int) (i->expires - squid_curtime),
	(int) i->addrs.count,
