	    storeAppendPrintf(sentry, "Last failed connect() at: %s\n",
		mkhttpdlogtime(&(e->last_fail_time)));
	}
	if (e->peer_domain != NULL) {
	    storeAppendPrintf(sentry, "DOMAIN LIST: ");
	    for (d = e->peer_domain; d; d = d->next) {
		storeAppendPrintf(sentry, "%s%s ",
		    d->do_ping ? null_string : "!", d->domain);
	    }