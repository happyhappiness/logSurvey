 * Call this from where the select loop fails.
 */
static int
examine_select(fd_set * readfds, fd_set * writefds)
{
    int fd = 0;
    fd_set read_x;
    fd_set write_x;
    struct timeval tv;
    close_handler *ch = NULL;
    fde *F = NULL;
    struct stat sb;
    debug(5, 0) ("examine_select: Examining open file descriptors...\n");
    for (fd = 0; fd < Squid_MaxFD; fd++) {
	FD_ZERO(&read_x);
	FD_ZERO(&write_x);
	tv.tv_sec = tv.tv_usec = 0;
	if (FD_ISSET(fd, readfds))
	    FD_SET(fd, &read_x);
	else if (FD_ISSET(fd, writefds))
	    FD_SET(fd, &write_x);
	else
	    continue;
	Counter.syscalls.selects++;
	errno = 0;
	if (!fstat(fd, &sb)) {
	    debug(5, 5) ("FD %d is valid.\n", fd);
	    continue;
	}
	F = &fd_table[fd];
	debug(5, 0) ("FD %d: %s\n", fd, xstrerror());
	debug(5, 0) ("WARNING: FD %d has handlers, but it's invalid.\n", fd);
	debug(5, 0) ("FD %d is a %s called '%s'\n",
	    fd,
	    fdTypeStr[F->type],
	    F->desc);
	debug(5, 0) ("tmout:%p read:%p write:%p\n",
	    F->timeout_handler,
	    F->read_handler,
	    F->write_handler);
	for (ch = F->close_handler; ch; ch = ch->next)
	    debug(5, 0) (" close handler: %p\n", ch->handler);
	if (F->close_handler) {
	    commCallCloseHandlers(fd);
	} else if (F->timeout_handler) {
	    debug(5, 0) ("examine_select: Calling Timeout Handler\n");
	    F->timeout_handler(fd, F->timeout_data);
	}
	F->close_handler = NULL;
	F->timeout_handler = NULL;
	F->read_handler = NULL;
	F->write_handler = NULL;
	FD_CLR(fd, readfds);
	FD_CLR(fd, writefds);
    }
    return 0;
}
#endif

static void
checkTimeouts(void)
{
    int fd;
    fde *F = NULL;
    PF *callback;
    for (fd = 0; fd <= Biggest_FD; fd++) {
	F = &fd_table[fd];
	if (!F->flags.open)
	    continue;
	if (F->timeout == 0)
	    continue;
	if (F->timeout > squid_curtime)
	    continue;
	debug(5, 5) ("checkTimeouts: FD %d Expired\n", fd);
	if (F->timeout_handler) {
	    debug(5, 5) ("checkTimeouts: FD %d: Call timeout handler\n", fd);
	    callback = F->timeout_handler;
	    F->timeout_handler = NULL;
	    callback(fd, F->timeout_data);
	} else {
	    debug(5, 5) ("checkTimeouts: FD %d: Forcing comm_close()\n", fd);
	    comm_close(fd);
	}
    }
}

static void
commIncomingStats(StoreEntry * sentry)
{
    StatCounters *f = &Counter;
    storeAppendPrintf(sentry, "Current incoming_icp_interval: %d\n",
	incoming_icp_interval >> INCOMING_FACTOR);
    storeAppendPrintf(sentry, "Current incoming_dns_interval: %d\n",
	incoming_dns_interval >> INCOMING_FACTOR);
    storeAppendPrintf(sentry, "Current incoming_http_interval: %d\n",
	incoming_http_interval >> INCOMING_FACTOR);
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "Histogram of events per incoming socket type\n");
#ifdef HAVE_POLL
    storeAppendPrintf(sentry, "ICP Messages handled per comm_poll_icp_incoming() call:\n");
#else
    storeAppendPrintf(sentry, "ICP Messages handled per comm_select_icp_incoming() call:\n");
#endif
    statHistDump(&f->comm_icp_incoming, sentry, statHistIntDumper);
#ifdef HAVE_POLL
    storeAppendPrintf(sentry, "DNS Messages handled per comm_poll_dns_incoming() call:\n");
#else
    storeAppendPrintf(sentry, "DNS Messages handled per comm_select_dns_incoming() call:\n");
#endif
    statHistDump(&f->comm_dns_incoming, sentry, statHistIntDumper);
#ifdef HAVE_POLL
    storeAppendPrintf(sentry, "HTTP Messages handled per comm_poll_http_incoming() call:\n");
#else
    storeAppendPrintf(sentry, "HTTP Messages handled per comm_select_http_incoming() call:\n");
#endif
    statHistDump(&f->comm_http_incoming, sentry, statHistIntDumper);
}

void
commUpdateReadBits(int fd, PF * handler)
{
    if (handler && !FD_ISSET(fd, &global_readfds)) {
	FD_SET(fd, &global_readfds);
	nreadfds++;
    } else if (!handler && FD_ISSET(fd, &global_readfds)) {
	FD_CLR(fd, &global_readfds);
	nreadfds--;
    }
}

void
commUpdateWriteBits(int fd, PF * handler)
{
    if (handler && !FD_ISSET(fd, &global_writefds)) {
	FD_SET(fd, &global_writefds);
	nwritefds++;
    } else if (!handler && FD_ISSET(fd, &global_writefds)) {
	FD_CLR(fd, &global_writefds);
	nwritefds--;
    }
}