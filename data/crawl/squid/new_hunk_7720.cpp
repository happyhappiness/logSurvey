    return 0;			/* XXX What is meaningful? */
}

void comm_add_close_handler(fd, handler, data)
     int fd;
     int (*handler) ();
     void *data;
{
    struct close_handler *new = xmalloc(sizeof(*new));

    debug(5, 5, "comm_add_close_handler: fd=%d handler=0x%p data=0x%p\n", fd, handler, data);

    new->handler = handler;
    new->data = data;
    new->next = fd_table[fd].close_handler;
    fd_table[fd].close_handler = new;
}

void comm_remove_close_handler(fd, handler, data)
     int fd;
     int (*handler) ();
     void *data;
{
    struct close_handler *p, *last = NULL;

    /* Find handler in list */
    for (p = fd_table[fd].close_handler; p != NULL; last = p, p = p->next)
	if (p->handler == handler && p->data == data)
	    break;		/* This is our handler */
    if (!p)
	fatal_dump("comm_remove_close_handler: Handler not found!\n");

    /* Remove list entry */
    if (last)
	last->next = p->next;
    else
	fd_table[fd].close_handler = p->next;
    safe_free(p);
}

static void commSetNoLinger(fd)
     int fd;
{
    struct linger L;
    L.l_onoff = 0;		/* off */
    L.l_linger = 0;
    debug(5, 10, "commSetNoLinger: turning off SO_LINGER on FD %d\n", fd);
    if (setsockopt(fd, SOL_SOCKET, SO_LINGER, (char *) &L, sizeof(L)) < 0)
	debug(5, 0, "commSetNoLinger: FD %d: %s\n", fd, xstrerror());
}

static void commSetReuseAddr(fd)
     int fd;
{
    int on = 1;
    debug(5, 10, "commSetReuseAddr: turning on SO_REUSEADDR on FD %d\n", fd);
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on)) < 0)
	debug(5, 1, "commSetReuseAddr: FD %d: %s\n", fd, xstrerror());
}

#ifdef TCP_NODELAY
static void commSetTcpNoDelay(fd)
     int fd;
{
    int on = 1;
    if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (char *) &on, sizeof(on)) < 0)
	debug(5, 1, "commSetTcpNoDelay: FD %d: %s\n", fd, xstrerror());
}
#endif

int commSetNonBlocking(fd)
     int fd;
{
#if defined(O_NONBLOCK) && !defined(_SQUID_SUNOS_) && !defined(_SQUID_SOLARIS_)
    if (fcntl(fd, F_SETFL, O_NONBLOCK)) {
	debug(5, 0, "comm_open: FD %d: error setting O_NONBLOCK: %s\n",
	    fd, xstrerror());
	return COMM_ERROR;
    }
#else
    if (fcntl(fd, F_SETFL, O_NDELAY)) {
	debug(5, 0, "comm_open: FD %d: error setting O_NDELAY: %s\n",
	    fd, xstrerror());
	return COMM_ERROR;
    }
#endif
    return 0;
}

