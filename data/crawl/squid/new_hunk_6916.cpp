    fail_ratio = 0.8;		/* reset to something less than 1.0 */
}
#endif

void
clientHttpConnectionsOpen(void)
{
    ushortlist *u;
    int fd;
debug(0,0)("clientHttpConnectionsOpen\n");
    for (u = Config.Port.http; u; u = u->next) {
debug(0,0)("clientHttpConnectionsOpen: port=%d\n", (int) u->i);
        enter_suid();
        fd = comm_open(SOCK_STREAM,
            0,
            Config.Addrs.tcp_incoming,
            u->i,
            COMM_NONBLOCKING,
            "HTTP Socket");
        leave_suid();
        if (fd < 0)
            continue;
        comm_listen(fd);
        commSetSelect(fd, COMM_SELECT_READ, httpAccept, NULL, 0);
        commSetDefer(fd, httpAcceptDefer, NULL);
        debug(1, 1) ("Accepting HTTP connections on port %d, FD %d.\n",
            (int) u->i, fd);
        HttpSockets[NHttpSockets++] = fd;
    }
    if (NHttpSockets < 1)
        fatal("Cannot open HTTP Port");
}
