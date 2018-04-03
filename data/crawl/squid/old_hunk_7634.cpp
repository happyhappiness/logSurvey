	IpcacheStats.avg_svc_time);
    storeAppendPrintf(sentry, "}\n\n");
    storeAppendPrintf(sentry, "{IP Cache Contents:\n\n");

    for (i = ipcache_GetFirst(); i; i = ipcache_GetNext()) {
	if (i->status == IP_PENDING || i->status == IP_DISPATCHED)
	    ttl = 0;
	else
	    ttl = (i->ttl + i->timestamp - squid_curtime);
	storeAppendPrintf(sentry, " {%-32.32s %c %6d %d",
	    i->name,
	    ipcache_status_char[i->status],
	    ttl,
	    (int) i->addr_count);
	for (k = 0; k < (int) i->addr_count; k++) {
	    struct in_addr addr;
	    xmemcpy(&addr, *(i->entry.h_addr_list + k), i->entry.h_length);
	    storeAppendPrintf(sentry, " %15s", inet_ntoa(addr));
	}
	for (k = 0; k < (int) i->alias_count; k++) {
	    storeAppendPrintf(sentry, " %s", i->entry.h_aliases[k]);
	}
	if (i->entry.h_name && strncmp(i->name, i->entry.h_name, MAX_LINELEN)) {
	    storeAppendPrintf(sentry, " %s", i->entry.h_name);
	}
	storeAppendPrintf(sentry, close_bracket);
    }
    storeAppendPrintf(sentry, close_bracket);
}
