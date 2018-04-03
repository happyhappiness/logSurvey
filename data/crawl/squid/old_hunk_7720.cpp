    return 0;			/* XXX What is meaningful? */
}


static int commSetNoLinger(fd)
     int fd;
{
    struct linger L;

    L.l_onoff = 0;		/* off */
    L.l_linger = 0;

    debug(5, 10, "commSetNoLinger: turning off SO_LINGER on FD %d\n", fd);
    return setsockopt(fd, SOL_SOCKET, SO_LINGER, (char *) &L, sizeof(L));
}

static int commSetReuseAddr(fd)
     int fd;
{
    int on = 1;
    int rc;

    debug(5, 10, "commSetReuseAddr: turning on SO_REUSEADDR on FD %d\n", fd);
    rc = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char *) &on, sizeof(on));
    if (rc < 0)
	debug(5, 1, "commSetReuseAddr: FD=%d: %s\n", fd, xstrerror());
    return rc;
}

int commSetNonBlocking(fd)
     int fd;
{
    debug(5, 10, "commSetNonBlocking: setting FD %d to non-blocking i/o.\n",
	fd);
    /*
     * Set up the flag NOT to have the socket to wait for message from
     * network forever, but to return -1 when no message is coming in.
     */

#if defined(O_NONBLOCK) && !defined(_SQUID_SUNOS_) && !defined(_SQUID_SOLARIS_)
    if (fcntl(fd, F_SETFL, O_NONBLOCK)) {
	debug(5, 0, "comm_open: FD %d: error setting O_NONBLOCK: %s\n",
	    fd, xstrerror());
	return (COMM_ERROR);
    }
#else
    if (fcntl(fd, F_SETFL, O_NDELAY)) {
	debug(5, 0, "comm_open: FD %d: error setting O_NDELAY: %s\n",
	    fd, xstrerror());
	return (COMM_ERROR);
    }
#endif /* HPUX */
    return 0;
}

