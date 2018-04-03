    }
    NRedirectors = getRedirectChildren();
    redirect_child_table = xcalloc(NRedirectors, sizeof(redirector_t *));
    debug(29, 1, "redirectOpenServers: Starting %d '%s' processes\n",
	NRedirectors, prg);
    for (k = 0; k < NRedirectors; k++) {
	redirect_child_table[k] = xcalloc(1, sizeof(redirector_t));
	if ((redirectsocket = redirectCreateRedirector(prg)) < 0) {
	    debug(29, 1, "WARNING: Cannot run '%s' process.\n", prg);
	    redirect_child_table[k]->flags &= ~REDIRECT_FLAG_ALIVE;
	} else {
	    redirect_child_table[k]->flags |= REDIRECT_FLAG_ALIVE;
	    redirect_child_table[k]->index = k;
	    redirect_child_table[k]->fd = redirectsocket;
	    redirect_child_table[k]->inbuf = get_free_4k_page();
	    redirect_child_table[k]->size = 4096;
	    redirect_child_table[k]->offset = 0;
	    sprintf(fd_note_buf, "%s #%d",
		prg,
		redirect_child_table[k]->index + 1);
	    fd_note(redirect_child_table[k]->fd, fd_note_buf);
	    commSetNonBlocking(redirect_child_table[k]->fd);
	    /* set handler for incoming result */
	    comm_set_select_handler(redirect_child_table[k]->fd,
		COMM_SELECT_READ,
		(PF) redirectHandleRead,
		(void *) redirect_child_table[k]);
	    debug(29, 3, "redirectOpenServers: 'redirect_server' %d started\n",
		k);
	}
    }
    if (first_time == 0) {
	first_time++;
	memset(&RedirectStats, '\0', sizeof(RedirectStats));
    }
}

void redirectShutdownServers()
{
    redirector_t *redirect = NULL;
    int k;
    if (!do_redirect)
	return;
    for (k = 0; k < NRedirectors; k++) {
	redirect = *(redirect_child_table + k);
	if (!(redirect->flags & REDIRECT_FLAG_ALIVE))
	    continue;
	if (redirect->flags & REDIRECT_FLAG_BUSY)
	    continue;
	if (redirect->flags & REDIRECT_FLAG_CLOSING)
	    continue;
	debug(29, 3, "redirectShutdownServers: closing redirector #%d, FD %d\n",
	    redirect->index + 1, redirect->fd);
	comm_close(redirect->fd);
	redirect->flags |= REDIRECT_FLAG_CLOSING;
    }
}


int redirectUnregister(url, fd)
     char *url;
     int fd;
{
    redirector_t *redirect = NULL;
    redirectStateData *r = NULL;
    struct redirectQueueData *rq = NULL;
    int k;
    int n = 0;
    if (!do_redirect)
	return 0;
    debug(29, 3, "redirectUnregister: FD %d '%s'\n", fd, url);
    for (k = 0; k < NRedirectors; k++) {
	redirect = *(redirect_child_table + k);
	if ((r = redirect->redirectState) == NULL)
	    continue;
	if (r->fd != fd)
	    continue;
	if (strcmp(r->orig_url, url))
	    continue;
	debug(29, 3, "redirectUnregister: Found match\n");
	r->handler = NULL;
	n++;
    }
    for (rq = redirectQueueHead; rq; rq = rq->next) {
	if ((r = rq->redirectState) == NULL)
	    continue;
	if (r->fd != fd)
	    continue;
	if (strcmp(r->orig_url, url))
	    continue;
	debug(29, 3, "redirectUnregister: Found match.\n");
	r->handler = NULL;
	n++;
    }
    debug(29, 3, "redirectUnregister: Unregistered %d handlers\n", n);
    return n;
}

void redirectStats(sentry)
     StoreEntry *sentry;
{
    int k;
    storeAppendPrintf(sentry, open_bracket);
    storeAppendPrintf(sentry, "{Redirector Statistics:}\n");
    storeAppendPrintf(sentry, "{requests: %d}\n",
	RedirectStats.requests);
    storeAppendPrintf(sentry, "{replies: %d}\n",
	RedirectStats.replies);
    storeAppendPrintf(sentry, "{queue length: %d}\n",
	RedirectStats.queue_size);
    storeAppendPrintf(sentry, "{avg service time: %d msec}\n",
	RedirectStats.avg_svc_time);
    storeAppendPrintf(sentry, "{number of redirectors: %d}\n",
	NRedirectors);
    storeAppendPrintf(sentry, "{use histogram:}\n");
    for (k = 0; k < NRedirectors; k++) {
	storeAppendPrintf(sentry, "{    redirector #%d: %d}\n",
	    k + 1,
	    RedirectStats.use_hist[k]);
    }
    storeAppendPrintf(sentry, close_bracket);
}
