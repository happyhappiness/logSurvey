	(int) (squid_curtime - i->lastref),
	(int) (i->expires - squid_curtime),
	i->addr_count);
    for (k = 0; k < (int) i->addr_count; k++) {
	struct in_addr addr;
	xmemcpy(&addr, i->entry.h_addr_list[k], i->entry.h_length);
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

