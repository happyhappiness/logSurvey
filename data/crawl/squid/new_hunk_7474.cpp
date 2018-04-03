    len += ulen + 1;
    icmpSendEcho(to, S_ICMP_ICP, payload, len);
    put_free_8k_page(payload);
#endif
}

void
icmpDomainPing(struct in_addr to, char *domain)
{
#if USE_ICMP
    debug(37, 3, "icmpDomainPing: '%s'\n", domain);
    icmpSendEcho(to, S_ICMP_DOM, domain, 0);
#endif
}

void
icmpOpen(void)
{
#if USE_ICMP
    struct sockaddr_in S;
    int namelen = sizeof(struct sockaddr_in);
    pid_t pid;
    int child_sock;
    icmp_sock = comm_open(SOCK_DGRAM,
	0,
	local_addr,
	0,
	COMM_NONBLOCKING,
	"ICMP Socket");
    if (icmp_sock < 0) {
	debug(37, 0, "icmpOpen: icmp_sock: %s\n", xstrerror());
	return;
    }
    child_sock = comm_open(SOCK_DGRAM,
	0,
	local_addr,
	0,
	0,
	"ICMP Socket");
    if (child_sock < 0) {
	debug(37, 0, "icmpOpen: child_sock: %s\n", xstrerror());
	return;
    }
    getsockname(icmp_sock, (struct sockaddr *) &S, &namelen);
    if (comm_connect_addr(child_sock, &S) != COMM_OK)
	fatal_dump(xstrerror());
    getsockname(child_sock, (struct sockaddr *) &S, &namelen);
    if (comm_connect_addr(icmp_sock, &S) != COMM_OK)
	fatal_dump(xstrerror());
    if ((pid = fork()) < 0) {
	debug(29, 0, "icmpOpen: fork: %s\n", xstrerror());
	comm_close(icmp_sock);
	comm_close(child_sock);
	return;
    }
    if (pid == 0) {		/* child */
	char *x = xcalloc(strlen(Config.debugOptions) + 32, 1);
	sprintf(x, "SQUID_DEBUG=%s\n", Config.debugOptions);
	putenv(x);
	comm_close(icmp_sock);
	dup2(child_sock, 0);
	dup2(child_sock, 1);
	comm_close(child_sock);
	dup2(fileno(debug_log), 2);
	fclose(debug_log);
	enter_suid();
	execlp(Config.Program.pinger, "(pinger)", NULL);
	debug(29, 0, "icmpOpen: %s: %s\n", Config.Program.pinger, xstrerror());
	_exit(1);
    }
    comm_close(child_sock);
    commSetSelect(icmp_sock,
	COMM_SELECT_READ,
	(PF) icmpRecv,
	(void *) -1, 0);
    comm_set_fd_lifetime(icmp_sock, -1);
    debug(29, 0, "Pinger socket opened on FD %d\n", icmp_sock);
#endif
}

void
icmpClose(void)
{
#if USE_ICMP
    icmpQueueData *queue;
    debug(29, 0, "Closing ICMP socket on FD %d\n", icmp_sock);
    comm_close(icmp_sock);
    commSetSelect(icmp_sock,
	COMM_SELECT_READ,
	NULL,
	NULL, 0);
    icmp_sock = -1;
    while ((queue = IcmpQueueHead)) {
	IcmpQueueHead = queue->next;
	if (queue->free_func)
	    queue->free_func(queue->msg);
	safe_free(queue);
    }
#endif
}
