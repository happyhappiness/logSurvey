ftpConnectDone(int fd, int status, void *data)
{
    FtpStateData *ftpState = data;
    if (status == COMM_ERROR) {
	squid_error_entry(ftpState->entry, ERR_CONNECT_FAIL, xstrerror());
	comm_close(fd);
	return;
    }
    commSetNonBlocking(fd);
    (void) fd_note(fd, ftpState->entry->url);
    /* Install connection complete handler. */
    fd_note(fd, ftpState->entry->url);
    commSetSelect(fd,
	COMM_SELECT_WRITE,
	ftpSendRequest,
	data, 0);
    if (opt_no_ipcache)
	ipcacheInvalidate(ftpState->request->host);
}

static void
ftpServerClosed(int fd, void *nodata)
{
    static time_t last_restart = 0;
    comm_close(fd);
    if (squid_curtime - last_restart < 2) {
	debug(9, 0, "ftpget server failing too rapidly\n");
	debug(9, 0, "WARNING: FTP access is disabled!\n");
	ftpget_server_write = -1;
	ftpget_server_read = -1;
	return;
    }
    last_restart = squid_curtime;
    debug(9, 1, "Restarting ftpget server...\n");
    (void) ftpInitialize();
}

void
ftpServerClose(void)
{
    /* NOTE: this function will be called repeatedly while shutdown is
     * pending */
    if (ftpget_server_read < 0)
	return;
    commSetSelect(ftpget_server_read,
	COMM_SELECT_READ,
	NULL,
	NULL, 0);
    fd_close(ftpget_server_read);
    close(ftpget_server_read);
    ftpget_server_read = -1;
    fd_close(ftpget_server_write);
    close(ftpget_server_write);
    ftpget_server_write = -1;
}


int
ftpInitialize(void)
{
    pid_t pid;
    int cfd;
    int squid_to_ftpget[2];
    int ftpget_to_squid[2];
    LOCAL_ARRAY(char, pbuf, 128);
    char *ftpget = Config.Program.ftpget;
    struct sockaddr_in S;
    int len;
    struct timeval slp;

    if (!strcmp(ftpget, "none")) {
	debug(9, 1, "ftpInitialize: ftpget is disabled.\n");
	return -1;
    }
    debug(9, 5, "ftpInitialize: Initializing...\n");
    if (pipe(squid_to_ftpget) < 0) {
	debug(50, 0, "ftpInitialize: pipe: %s\n", xstrerror());
	return -1;
    }
    if (pipe(ftpget_to_squid) < 0) {
	debug(50, 0, "ftpInitialize: pipe: %s\n", xstrerror());
	return -1;
    }
    cfd = comm_open(SOCK_STREAM,
	0,
	local_addr,
	0,
	COMM_NOCLOEXEC,
	"ftpget -S socket");
    debug(9, 5, "ftpget -S socket on FD %d\n", cfd);
    if (cfd == COMM_ERROR) {
	debug(9, 0, "ftpInitialize: Failed to create socket\n");
	return -1;
    }
    len = sizeof(S);
    memset(&S, '\0', len);
    if (getsockname(cfd, (struct sockaddr *) &S, &len) < 0) {
	debug(50, 0, "ftpInitialize: getsockname: %s\n", xstrerror());
	comm_close(cfd);
	return -1;
    }
    ftpget_port = ntohs(S.sin_port);
    listen(cfd, Squid_MaxFD >> 2);
    if ((pid = fork()) < 0) {
	debug(50, 0, "ftpInitialize: fork: %s\n", xstrerror());
	comm_close(cfd);
	fatal("Failed to fork() for ftpget.");
    }
    if (pid != 0) {		/* parent */
	comm_close(cfd);
	close(squid_to_ftpget[0]);
	close(ftpget_to_squid[1]);
	fd_open(squid_to_ftpget[1], FD_PIPE, "squid -> ftpget");
	fd_open(ftpget_to_squid[0], FD_PIPE, "squid <- ftpget");
	commSetCloseOnExec(squid_to_ftpget[1]);
	commSetCloseOnExec(ftpget_to_squid[0]);
	/* if ftpget -S goes away, this handler should get called */
	commSetSelect(ftpget_to_squid[0],
	    COMM_SELECT_READ,
	    ftpServerClosed,
	    NULL, 0);
	ftpget_server_write = squid_to_ftpget[1];
	ftpget_server_read = ftpget_to_squid[0];
	slp.tv_sec = 0;
	slp.tv_usec = 250000;
	select(0, NULL, NULL, NULL, &slp);
	return 0;
    }
    /* child */
    /* give up all extra priviligies */
    no_suid();
    /* set up stdin,stdout */
    dup2(squid_to_ftpget[0], 0);
    dup2(ftpget_to_squid[1], 1);
    dup2(fileno(debug_log), 2);
    close(squid_to_ftpget[0]);
    close(squid_to_ftpget[1]);
    close(ftpget_to_squid[0]);
    close(ftpget_to_squid[1]);
    dup2(cfd, 3);		/* pass listening socket to ftpget */
    /* inherit stdin,stdout,stderr */
    for (cfd = 4; cfd <= Biggest_FD; cfd++)
	(void) close(cfd);
    sprintf(pbuf, "%d", ftpget_port);
    execlp(ftpget, ftpget, "-S", pbuf, NULL);
    debug(50, 0, "ftpInitialize: %s: %s\n", ftpget, xstrerror());
    _exit(1);
    return (1);			/* eliminate compiler warning */
}
