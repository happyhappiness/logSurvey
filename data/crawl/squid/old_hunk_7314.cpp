	    FqdncacheStats.hits++;
	fqdncacheAddPending(f, fd, handler, handlerData);
	fqdncache_call_pending(f);
	return 0;
    } else if (f->status == FQDN_PENDING || f->status == FQDN_DISPATCHED) {
	debug(35, 4, "fqdncache_nbgethostbyaddr: PENDING for '%s'\n", name);
	FqdncacheStats.pending_hits++;
	fqdncacheAddPending(f, fd, handler, handlerData);
	return 0;
    } else {
	fatal_dump("fqdncache_nbgethostbyaddr: BAD fqdncache_entry status");
    }

    /* for HIT, PENDING, DISPATCHED we've returned.  For MISS we continue */

    if ((dnsData = dnsGetFirstAvailable()))
	fqdncache_dnsDispatch(dnsData, f);
    else
	fqdncacheEnqueue(f);
    return 0;
}

static void
