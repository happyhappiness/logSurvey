ipcacheStatPrint(ipcache_entry * i, StoreEntry * sentry)
{
    int k;
    storeAppendPrintf(sentry, " {%-32.32s  %c%c %6d %6d %d",
	i->name,
	ipcache_status_char[i->status],
	i->locks ? 'L' : ' ',
	(int) (squid_curtime - i->lastref),
	(int) (i->expires - squid_curtime),
	(int) i->addrs.count);
    for (k = 0; k < (int) i->addrs.count; k++)
	storeAppendPrintf(sentry, " %15s", inet_ntoa(i->addrs.in_addrs[k]));
    storeAppendPrintf(sentry, close_bracket);
}

