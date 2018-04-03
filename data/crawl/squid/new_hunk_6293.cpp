		e->icp.counts[op],
		percent(e->icp.counts[op], e->stats.pings_acked));
	}
#if USE_HTCP
}
#endif
	if (e->last_fail_time) {
	    storeAppendPrintf(sentry, "Last failed connect() at: %s\n",
		mkhttpdlogtime(&(e->last_fail_time)));
	}
	if (e->pinglist != NULL) {
	    storeAppendPrintf(sentry, "DOMAIN LIST: ");
	    for (d = e->pinglist; d; d = d->next) {
		    storeAppendPrintf(sentry, "%s%s ",
			d->do_ping ? null_string : "!", d->domain);
	    }
	    storeAppendPrintf(sentry, "\n");
	}
	storeAppendPrintf(sentry, "keep-alive ratio: %d%%\n",
	    percent(e->stats.n_keepalives_recv, e->stats.n_keepalives_sent));
    }
