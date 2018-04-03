	if (e->pinglist != NULL) {
	    storeAppendPrintf(sentry, "DOMAIN LIST: ");
	    for (d = e->pinglist; d; d = d->next) {
		storeAppendPrintf(sentry, "%s%s ",
		    d->do_ping ? null_string : "!", d->domain);
	    }
	    storeAppendPrintf(sentry, "\n");
	}
