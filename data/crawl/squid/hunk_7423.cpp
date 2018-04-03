 		maxfd = fd;
 	}
     }
-
     if (maxfd++ == 0)
 	return;
-    if (select(maxfd, &read_mask, &write_mask, NULL, &zero_tv) > 0) {
-	getCurrentTime();
-	for (i = 0; i < N; i++) {
-	    fd = fds[i];
-	    if (FD_ISSET(fd, &read_mask)) {
-		hdl = fd_table[fd].read_handler;
-		fd_table[fd].read_handler = 0;
-		hdl(fd, fd_table[fd].read_data);
+    if (select(maxfd, &read_mask, &write_mask, NULL, &zero_tv) < 1)
+	return;
+    getCurrentTime();
+    for (i = 0; i < N; i++) {
+	fd = fds[i];
+	if (FD_ISSET(fd, &read_mask)) {
+	    hdl = fd_table[fd].read_handler;
+	    fd_table[fd].read_handler = 0;
+	    hdl(fd, fd_table[fd].read_data);
+	}
+	if (FD_ISSET(fd, &write_mask)) {
+	    hdl = fd_table[fd].write_handler;
+	    fd_table[fd].write_handler = 0;
+	    hdl(fd, fd_table[fd].write_data);
+	}
+    }
+}
+#endif
+
+
+#ifdef USE_POLL
+/* poll all sockets; call handlers for those that are ready. */
+int
+comm_select(time_t sec)
+{
+    struct pollfd pfds[FD_SETSIZE];
+    PF hdl = NULL;
+    int fd;
+    int i;
+    int maxfd;
+    int nfds;
+    int incnfd;
+    int num;
+    int httpindex;
+    static time_t last_timeout = 0;
+    int poll_time = 0;
+    time_t timeout;
+    struct close_handler *ch = NULL;
+    struct close_handler *next = NULL;
+    FD_ENTRY *f = NULL;
+    /* assume all process are very fast (less than 1 second). Call
+     * time() only once */
+    getCurrentTime();
+    /* use only 1 second granularity */
+    timeout = squid_curtime + sec;
+    do {
+	if (sec > 60)
+	    fatal_dump(NULL);
+	if (shutdown_pending || reread_pending) {
+	    serverConnectionsClose();
+	    ftpServerClose();
+	    dnsShutdownServers();
+	    redirectShutdownServers();
+	    if (shutdown_pending > 0)
+		setSocketShutdownLifetimes(Config.lifetimeShutdown);
+	    else
+		setSocketShutdownLifetimes(0);
+	}
+	nfds = 0;
+	maxfd = fdstat_biggest_fd() + 1;
+	httpindex = -1;
+	for (i = 0; i < maxfd; i++) {
+	    pfds[nfds].fd = -1;
+	    pfds[nfds].events = 0;
+#if USE_ASYNC_IO
+	    /* Using async IO for disk handle, so don't select on them */
+	    if (fdstatGetType(i) == FD_FILE)
+		continue;
+#endif
+	    /* Check each open socket for a handler. */
+	    incnfd = 0;
+	    if (fd_table[i].read_handler && fd_table[i].stall_until <= squid_curtime) {
+		pfds[nfds].events |= POLLRDNORM;
+		pfds[nfds].fd = i;
+		incnfd = 1;
 	    }
-	    if (FD_ISSET(fd, &write_mask)) {
-		hdl = fd_table[fd].write_handler;
-		fd_table[fd].write_handler = 0;
-		hdl(fd, fd_table[fd].write_data);
+	    if (fd_table[i].write_handler) {
+		pfds[nfds].events |= POLLWRNORM;
+		pfds[nfds].fd = i;
+		incnfd = 1;
+	    }
+	    if (incnfd == 1) {
+		if (i == theHttpConnection)
+		    httpindex = nfds;
+		nfds++;
 	    }
 	}
-    }
+	/* If we're out of free fd's, don't poll the http incoming fd */
+	if (!fdstat_are_n_free_fd(RESERVED_FD) && httpindex >= 0) {
+	    pfds[httpindex].fd = -1;
+	    pfds[httpindex].events = 0;
+	}
+	pfds[nfds].fd = -1;	/* just in case */
+	pfds[nfds].events = 0;
+	if (shutdown_pending || reread_pending)
+	    debug(5, 2, "comm_select: Still waiting on %d FDs\n", nfds);
+	if (nfds == 0)
+	    return COMM_SHUTDOWN;
+	for (;;) {
+#if USE_ASYNC_IO
+	    /* Another CPU vs latency tradeoff for async IO */
+	    poll_time = 250;
+#else
+	    poll_time = sec > 0 ? 1000 : 0;
+#endif
+	    num = poll(pfds, nfds, poll_time);
+	    getCurrentTime();
+	    if (num >= 0)
+		break;
+	    if (errno == EINTR)
+		break;
+	    debug(5, 0, "comm_select: poll failure: %s\n",
+		xstrerror());
+	    if (errno == EINVAL) {
+		/* nfds greater than OPEN_MAX?? How possible? Time */
+		/* to bail - write out nfds to cache.log and start */
+		/* emergency shutdown by sending SIGTERM to self */
+		debug(20, 1, "  Poll died with EINVAL. Tried to poll %d FD's\n", nfds);
+		kill(getpid(), SIGTERM);
+	    }
+	    /* examine_select is handled below and efficiently too */
+	    /*examine_select(&readfds, &writefds); XXXXX TO FIX */
+	    return COMM_ERROR;
+	    /* NOTREACHED */
+	}
+#if USE_ASYNC_IO
+	aioExamine();		/* See if any IO completed */
+#endif
+	if (num < 0)
+	    continue;		/* redo the top loop */
+	debug(5, num ? 5 : 8, "comm_select: %d sockets ready at %d\n",
+	    num, (int) squid_curtime);
+	/* Check lifetime and timeout handlers ONCE each second.
+	 * Replaces brain-dead check every time through the loop! */
+	if (squid_curtime > last_timeout) {
+	    last_timeout = squid_curtime;
+	    checkTimeouts();
+	    checkLifetimes();
+	}
+	if (num == 0)
+	    continue;
+	/* scan each socket but the accept socket. Poll this 
+	 * more frequently to minimiize losses due to the 5 connect 
+	 * limit in SunOS */
+	for (i = 0; i < nfds; i++) {
+	    fd = pfds[i].fd;
+	    if ((fd == -1) || (pfds[i].revents == 0))
+		continue;
+	    /*
+	     * Admit more connections quickly until we hit the hard limit.
+	     * Don't forget to keep the UDP acks coming and going.
+	     */
+	    comm_select_incoming();
+	    if ((fd == theInIcpConnection) || (fd == theHttpConnection))
+		continue;
+	    if (pfds[i].revents & (POLLRDNORM | POLLIN | POLLHUP | POLLERR)) {
+		debug(5, 6, "comm_select: FD %d ready for reading\n", fd);
+		if (fd_table[fd].read_handler) {
+		    hdl = fd_table[fd].read_handler;
+		    fd_table[fd].read_handler = 0;
+		    hdl(fd, fd_table[fd].read_data);
+		}
+	    }
+	    if (pfds[i].revents & (POLLWRNORM | POLLOUT | POLLHUP | POLLERR)) {
+		debug(5, 5, "comm_select: FD %d ready for writing\n", fd);
+		if (fd_table[fd].write_handler) {
+		    hdl = fd_table[fd].write_handler;
+		    fd_table[fd].write_handler = 0;
+		    hdl(fd, fd_table[fd].write_data);
+		}
+	    }
+	    if (pfds[i].revents & POLLNVAL) {
+		f = &fd_table[fd];
+		debug(5, 0, "WARNING: FD %d has handlers, but it's invalid.\n", fd);
+		debug(5, 0, "FD %d is a %s\n", fd, fdstatTypeStr[fdstatGetType(fd)]);
+		debug(5, 0, "--> %s\n", fd_note(fd, NULL));
+		debug(5, 0, "lifetm:%p tmout:%p read:%p write:%p\n",
+		    f->lifetime_handler,
+		    f->timeout_handler,
+		    f->read_handler,
+		    f->write_handler);
+		for (ch = f->close_handler; ch; ch = ch->next)
+		    debug(5, 0, " close handler: %p\n", ch->handler);
+		if (f->close_handler) {
+		    for (ch = f->close_handler; ch; ch = next) {
+			next = ch->next;
+			ch->handler(fd, ch->data);
+			safe_free(ch);
+		    }
+		} else if (f->lifetime_handler) {
+		    debug(5, 0, "examine_select: Calling Lifetime Handler\n");
+		    f->lifetime_handler(fd, f->lifetime_data);
+		} else if (f->timeout_handler) {
+		    debug(5, 0, "examine_select: Calling Timeout Handler\n");
+		    f->timeout_handler(fd, f->timeout_data);
+		}
+		f->close_handler = NULL;
+		f->lifetime_handler = NULL;
+		f->timeout_handler = NULL;
+		f->read_handler = NULL;
+		f->write_handler = NULL;
+	    }
+	}
+	return COMM_OK;
+    } while (timeout > getCurrentTime());
+    debug(5, 8, "comm_select: time out: %d.\n", squid_curtime);
+    return COMM_TIMEOUT;
 }
 
+#else
 
 /* Select on all sockets; call handlers for those that are ready. */
 int
