	*me = M;
    }
    /* fdstat update */
    fdstat_open(sock, Socket);
    conn = &fd_table[sock];
    conn->openned = 1;
    conn->sender = 0;		/* This is an accept, therefore receiver. */
    conn->comm_type = listener->comm_type;
    strcpy(conn->ipaddr, inet_ntoa(P.sin_addr));

    commSetNonBlocking(sock);

    return sock;
}

int comm_close(fd)
     int fd;
{
    FD_ENTRY *conn = NULL;

    if (fd < 0)
	return -1;

    if (fdstat_type(fd) == File) {
	debug(5, 0, "FD %d: Someone called comm_close() on a File\n", fd);
	fatal_dump(NULL);
    }
    conn = &fd_table[fd];

    comm_set_fd_lifetime(fd, -1);	/* invalidate the lifetime */
    debug(5, 5, "comm_close: FD %d\n", fd);
    /* update fdstat */
    fdstat_close(fd);
    if (conn->close_handler)
	conn->close_handler(fd, conn->close_data);
    memset(conn, '\0', sizeof(FD_ENTRY));
    return close(fd);
}
