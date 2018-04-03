	if (f->status == FQDN_PENDING || f->status == FQDN_DISPATCHED)
	    ttl = 0;
	else
	    ttl = (f->expires - squid_curtime);
	storeAppendPrintf(sentry, " {%-32.32s %c %6d %d",
	    f->name,
	    fqdncache_status_char[f->status],