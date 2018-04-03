 ftpConnectDone(int fd, int status, void *data)
 {
     FtpStateData *ftpState = data;
+    debug(0, 0, "ftpConnectDone\n");
     if (status == COMM_ERROR) {
 	squid_error_entry(ftpState->entry, ERR_CONNECT_FAIL, xstrerror());
 	comm_close(fd);
 	return;
     }
-    commSetNonBlocking(fd);
-    (void) fd_note(fd, ftpState->entry->url);
-    /* Install connection complete handler. */
-    fd_note(fd, ftpState->entry->url);
-    commSetSelect(fd,
-	COMM_SELECT_WRITE,
-	ftpSendRequest,
-	data, 0);
-    if (opt_no_ipcache)
-	ipcacheInvalidate(ftpState->request->host);
+    ftpState->state = BEGIN;
+    ftpState->ctrl.buf = get_free_4k_page();
+    ftpState->ctrl.freefunc = put_free_4k_page;
+    ftpState->ctrl.size = 4096;
+    ftpState->ctrl.offset = 0;
+    ftpState->data.buf = xmalloc(SQUID_TCP_SO_RCVBUF);
+    ftpState->data.size = SQUID_TCP_SO_RCVBUF;
+    ftpState->data.freefunc = xfree;
+    commSetSelect(fd, COMM_SELECT_READ, ftpReadControlReply, ftpState, 0);
 }
 
+/* ====================================================================== */
+
+
 static void
-ftpServerClosed(int fd, void *nodata)
+ftpWriteCommand(const char *buf, FtpStateData * ftpState)
 {
-    static time_t last_restart = 0;
-    comm_close(fd);
-    if (squid_curtime - last_restart < 2) {
-	debug(9, 0, "ftpget server failing too rapidly\n");
-	debug(9, 0, "WARNING: FTP access is disabled!\n");
-	ftpget_server_write = -1;
-	ftpget_server_read = -1;
+    debug(0, 0, "ftpWriteCommand: %s\n", buf);
+    comm_write(ftpState->ctrl.fd,
+	xstrdup(buf),
+	strlen(buf),
+	ftpWriteCommandCallback,
+	ftpState,
+	xfree);
+    commSetSelect(ftpState->ctrl.fd,
+	COMM_SELECT_READ,
+	ftpReadControlReply,
+	ftpState,
+	0);
+}
+
+static void
+ftpWriteCommandCallback(int fd, char *buf, int size, int errflag, void *data)
+{
+    FtpStateData *ftpState = data;
+    StoreEntry *entry = ftpState->entry;
+    debug(0, 0, "ftpWriteCommandCallback: wrote %d bytes\n", size);
+    if (errflag) {
+	BIT_RESET(entry->flag, ENTRY_CACHABLE);
+	storeReleaseRequest(entry);
+	squid_error_entry(entry, ERR_WRITE_ERROR, xstrerror());
+	comm_close(fd);
+    }
+}
+
+static wordlist *
+ftpParseControlReply(char *buf, size_t len, int *codep)
+{
+    char *s;
+    int complete = 0;
+    wordlist *head;
+    wordlist *list;
+    wordlist **tail = &head;
+    off_t offset;
+    size_t linelen;
+    int code;
+    debug(0, 0, "ftpParseControlReply\n");
+    if (*(buf + len - 1) != '\n')
+	return NULL;
+    for (s = buf; s - buf < len; s += strcspn(s, crlf), s += strspn(s, crlf)) {
+	linelen = strcspn(s, crlf) + 1;
+	if (linelen > 3)
+	    complete = (*s >= '0' && *s <= '9' && *(s + 3) == ' ');
+	if (complete)
+	    code = atoi(s);
+	offset = 0;
+	if (linelen > 3)
+	    if (*s >= '0' && *s <= '9' && (*(s + 3) == '-' || *(s + 3) == ' '))
+		offset = 4;
+	list = xcalloc(1, sizeof(wordlist));
+	list->key = xmalloc(linelen - offset);
+	xstrncpy(list->key, s + offset, linelen - offset);
+	debug(38, 0, "%s\n", list->key);
+	*tail = list;
+	tail = &list->next;
+    }
+    if (!complete)
+	wordlistDestroy(&head);
+    if (codep)
+	*codep = code;
+    return head;
+}
+
+static void
+ftpReadControlReply(int fd, void *data)
+{
+    FtpStateData *ftpState = data;
+    StoreEntry *entry = ftpState->entry;
+    char *oldbuf;
+    wordlist **W;
+    int len;
+    debug(0, 0, "ftpReadControlReply\n");
+    assert(ftpState->ctrl.offset < ftpState->ctrl.size);
+    len = read(fd,
+	ftpState->ctrl.buf + ftpState->ctrl.offset,
+	ftpState->ctrl.size - ftpState->ctrl.offset);
+    fd_bytes(fd, len, FD_READ);
+    debug(9, 5, "ftpReadControlReply: FD %d, Read %d bytes\n", fd, len);
+    if (len > 0)
+	commSetTimeout(fd, Config.Timeout.read, NULL, NULL);
+    if (entry->flag & CLIENT_ABORT_REQUEST) {
+	squid_error_entry(entry, ERR_CLIENT_ABORT, NULL);
+	comm_close(fd);
 	return;
     }
-    last_restart = squid_curtime;
-    debug(9, 1, "Restarting ftpget server...\n");
-    (void) ftpInitialize();
+    if (len < 0) {
+	debug(50, 1, "ftpReadControlReply: read error: %s\n", xstrerror());
+	if (errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR) {
+	    commSetSelect(fd,
+		COMM_SELECT_READ,
+		ftpReadControlReply,
+		ftpState,
+		0);
+	} else {
+	    BIT_RESET(entry->flag, ENTRY_CACHABLE);
+	    storeReleaseRequest(entry);
+	    squid_error_entry(entry, ERR_READ_ERROR, xstrerror());
+	    comm_close(fd);
+	}
+	return;
+    }
+    if (len == 0) {
+	debug(38, 0, "Read 0 bytes from FTP control socket?\n");
+	BIT_RESET(entry->flag, ENTRY_CACHABLE);
+	storeReleaseRequest(entry);
+	squid_error_entry(entry, ERR_READ_ERROR, xstrerror());
+	comm_close(fd);
+	return;
+    }
+    assert(len <= ftpState->ctrl.size);
+    wordlistDestroy(&ftpState->ctrl.message);
+    ftpState->ctrl.message = ftpParseControlReply(ftpState->ctrl.buf, len,
+	&ftpState->ctrl.replycode);
+    if (ftpState->ctrl.message == NULL) {
+	if (len == ftpState->ctrl.size) {
+	    oldbuf = ftpState->ctrl.buf;
+	    ftpState->ctrl.buf = xcalloc(ftpState->ctrl.size << 1, 1);
+	    xmemcpy(ftpState->ctrl.buf, oldbuf, ftpState->ctrl.size);
+	    ftpState->ctrl.size <<= 1;
+	    ftpState->ctrl.freefunc(oldbuf);
+	    ftpState->ctrl.freefunc = xfree;
+	}
+	commSetSelect(fd, COMM_SELECT_READ, ftpReadControlReply, ftpState, 0);
+	return;
+    }
+    for (W = &ftpState->ctrl.message; *W && (*W)->next; W = &(*W)->next);
+    ftpState->ctrl.last_message = (*W)->key;
+    safe_free(*W);
+    ftpState->ctrl.offset = 0;
+    FTP_SM_FUNCS[ftpState->state] (ftpState);
 }
 
-void
-ftpServerClose(void)
+/* ====================================================================== */
+
+static void
+ftpReadWelcome(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    char *p = NULL;
+    debug(0, 0, "ftpReadWelcome\n");
+    if (EBIT_TEST(ftpState->flags, FTP_PASV_ONLY))
+	ftpState->login_att++;
+    if (code == 220) {
+	if (ftpState->ctrl.message)
+	    if (strstr(ftpState->ctrl.message->key, "NetWare"))
+		EBIT_SET(ftpState->flags, FTP_SKIP_WHITESPACE);
+	if (ftpState->proxy_host != NULL)
+	    sprintf(cbuf, "USER %s@%s\r\n",
+		ftpState->user,
+		ftpState->request->host);
+	else
+	    sprintf(cbuf, "USER %s\r\n", ftpState->user);
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_USER;
+    } else {
+	ftpFail(ftpState);
+    }
+}
+
+static void
+ftpReadUser(FtpStateData * ftpState)
 {
-    /* NOTE: this function will be called repeatedly while shutdown is
-     * pending */
-    if (ftpget_server_read < 0)
+    int code = ftpState->ctrl.replycode;
+    debug(0, 0, "ftpReadUser\n");
+    if (code == 230) {
+	ftpReadPass(ftpState);
+    } else if (code == 331) {
+	sprintf(cbuf, "PASS %s\r\n", ftpState->password);
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_PASS;
+    } else {
+	ftpFail(ftpState);
+    }
+}
+
+static void
+ftpReadPass(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    char *t;
+    char *filename;
+    char mode;
+    debug(0, 0, "ftpReadPass\n");
+    if (code == 230) {
+	t = strrchr(ftpState->request->urlpath, '/');
+	filename = t ? t + 1 : ftpState->request->urlpath;
+	mode = mimeGetTransferMode(filename);
+	sprintf(cbuf, "TYPE %c\r\n", mode);
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_TYPE;
+    } else {
+	ftpFail(ftpState);
+    }
+}
+
+static void
+ftpReadType(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    wordlist *w;
+    wordlist **T;
+    char *path;
+    char *d;
+    debug(38, 1, "This is ftpReadType\n");
+    if (code == 200) {
+	if (EBIT_TEST(ftpState->flags, FTP_ROOT_DIR)) {
+	    ftpSendPasv(ftpState);
+	} else {
+	    path = xstrdup(ftpState->request->urlpath);
+	    T = &ftpState->pathcomps;
+	    for (d = strtok(path, "/"); d; d = strtok(NULL, "/")) {
+		w = xcalloc(1, sizeof(wordlist));
+		w->key = xstrdup(d);
+		*T = w;
+		T = &w->next;
+	    }
+	    ftpSendCwd(ftpState);
+	}
+    } else {
+	ftpFail(ftpState);
+    }
+}
+
+static void
+ftpSendCwd(FtpStateData * ftpState)
+{
+    wordlist *w;
+    debug(0, 0, "ftpSendCwd\n");
+    if ((w = ftpState->pathcomps) == NULL) {
+	debug(0, 0, "the final component was a directory\n");
+	EBIT_SET(ftpState->flags, FTP_ISDIR);
+	if (!EBIT_TEST(ftpState->flags, FTP_ROOT_DIR))
+	    strcat(ftpState->title_url, "/");
+	ftpSendPasv(ftpState);
 	return;
-    commSetSelect(ftpget_server_read,
-	COMM_SELECT_READ,
-	NULL,
-	NULL, 0);
-    fd_close(ftpget_server_read);
-    close(ftpget_server_read);
-    ftpget_server_read = -1;
-    fd_close(ftpget_server_write);
-    close(ftpget_server_write);
-    ftpget_server_write = -1;
-}
-
-
-int
-ftpInitialize(void)
-{
-    pid_t pid;
-    int cfd;
-    int squid_to_ftpget[2];
-    int ftpget_to_squid[2];
-    LOCAL_ARRAY(char, pbuf, 128);
-    char *ftpget = Config.Program.ftpget;
-    struct sockaddr_in S;
-    int len;
-    struct timeval slp;
+    }
+    sprintf(cbuf, "CWD %s\r\n", w->key);
+    ftpWriteCommand(cbuf, ftpState);
+    ftpState->state = SENT_CWD;
+}
 
-    if (!strcmp(ftpget, "none")) {
-	debug(9, 1, "ftpInitialize: ftpget is disabled.\n");
-	return -1;
+static void
+ftpReadCwd(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    size_t len = 0;
+    wordlist *w;
+    debug(38, 1, "This is ftpReadCwd\n");
+    w = ftpState->pathcomps;
+    assert(w != NULL);
+    if (code >= 200 && code < 300) {
+	if (ftpState->cwd_message)
+	    wordlistDestroy(&ftpState->cwd_message);
+	ftpState->cwd_message = ftpState->ctrl.message;
+	ftpState->ctrl.message = NULL;
+	/* CWD OK */
+	ftpState->pathcomps = w->next;
+	xfree(w->key);
+	xfree(w);
+	ftpSendCwd(ftpState);
+    } else {
+	/* CWD FAILED */
+	while (w) {
+	    len += (strlen(w->key) + 1);
+	    w = w->next;
+	}
+	ftpState->filepath = xcalloc(len, 1);
+	for (w = ftpState->pathcomps; w; w = w->next) {
+	    strcat(ftpState->filepath, w->key);
+	    if (w->next)
+		strcat(ftpState->filepath, "/");
+	}
+	wordlistDestroy(&ftpState->pathcomps);
+	assert(*ftpState->filepath != '\0');
+	sprintf(cbuf, "MDTM %s\r\n", ftpState->filepath);
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_MDTM;
     }
-    debug(9, 5, "ftpInitialize: Initializing...\n");
-    if (pipe(squid_to_ftpget) < 0) {
-	debug(50, 0, "ftpInitialize: pipe: %s\n", xstrerror());
-	return -1;
+}
+
+static void
+ftpReadMdtm(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    debug(38, 1, "This is ftpReadMdtm\n");
+    if (code == 213) {
+	ftpState->mdtm = parse_iso3307_time(ftpState->ctrl.last_message);
+	assert(ftpState->filepath != NULL);
+	assert(*ftpState->filepath != '\0');
+	sprintf(cbuf, "SIZE %s\r\n", ftpState->filepath);
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_SIZE;
+    } else if (code < 0) {
+	ftpFail(ftpState);
     }
-    if (pipe(ftpget_to_squid) < 0) {
-	debug(50, 0, "ftpInitialize: pipe: %s\n", xstrerror());
-	return -1;
+}
+
+static void
+ftpReadSize(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    debug(38, 1, "This is ftpReadSize\n");
+    if (code == 213) {
+	ftpState->size = atoi(ftpState->ctrl.last_message);
+	ftpSendPasv(ftpState);
+    } else if (code < 0) {
+	ftpFail(ftpState);
+    }
+}
+
+static void
+ftpSendPasv(FtpStateData * ftpState)
+{
+    int fd;
+    assert(ftpState->data.fd < 0);
+    if (!EBIT_TEST(ftpState->flags, FTP_PASV_SUPPORTED)) {
+	ftpSendPort(ftpState);
+	return;
     }
-    cfd = comm_open(SOCK_STREAM,
+    fd = comm_open(SOCK_STREAM,
 	0,
-	local_addr,
+	Config.Addrs.tcp_outgoing,
 	0,
-	COMM_NOCLOEXEC,
-	"ftpget -S socket");
-    debug(9, 5, "ftpget -S socket on FD %d\n", cfd);
-    if (cfd == COMM_ERROR) {
-	debug(9, 0, "ftpInitialize: Failed to create socket\n");
-	return -1;
-    }
-    len = sizeof(S);
-    memset(&S, '\0', len);
-    if (getsockname(cfd, (struct sockaddr *) &S, &len) < 0) {
-	debug(50, 0, "ftpInitialize: getsockname: %s\n", xstrerror());
-	comm_close(cfd);
-	return -1;
-    }
-    ftpget_port = ntohs(S.sin_port);
-    listen(cfd, Squid_MaxFD >> 2);
-    if ((pid = fork()) < 0) {
-	debug(50, 0, "ftpInitialize: fork: %s\n", xstrerror());
-	comm_close(cfd);
-	fatal("Failed to fork() for ftpget.");
-    }
-    if (pid != 0) {		/* parent */
-	comm_close(cfd);
-	close(squid_to_ftpget[0]);
-	close(ftpget_to_squid[1]);
-	fd_open(squid_to_ftpget[1], FD_PIPE, "squid -> ftpget");
-	fd_open(ftpget_to_squid[0], FD_PIPE, "squid <- ftpget");
-	commSetCloseOnExec(squid_to_ftpget[1]);
-	commSetCloseOnExec(ftpget_to_squid[0]);
-	/* if ftpget -S goes away, this handler should get called */
-	commSetSelect(ftpget_to_squid[0],
+	COMM_NONBLOCKING,
+	ftpState->entry->url);
+    if (fd < 0) {
+	ftpFail(ftpState);
+	return;
+    }
+    ftpState->data.fd = fd;
+    commSetTimeout(fd, Config.Timeout.read, ftpTimeout, ftpState);
+    sprintf(cbuf, "PASV\r\n");
+    ftpWriteCommand(cbuf, ftpState);
+    ftpState->state = SENT_PASV;
+}
+
+static void
+ftpReadPasv(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    int h1, h2, h3, h4;
+    int p1, p2;
+    int n;
+    u_short port;
+    int fd = ftpState->data.fd;
+    char *buf = ftpState->ctrl.last_message;
+    LOCAL_ARRAY(char, junk, 1024);
+    debug(38, 1, "This is ftpReadPasv\n");
+    if (code != 227) {
+	debug(38, 0, "PASV not supported by remote end\n");
+	ftpSendPort(ftpState);
+	return;
+    }
+    if (strlen(buf) > 1024) {
+	debug(38, 0, "Avoiding potential buffer overflow\n");
+	ftpSendPort(ftpState);
+	return;
+    }
+    /*  227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).  */
+    /*  ANSI sez [^0-9] is undefined, it breaks on Watcom cc */
+    debug(0, 0, "scanning: %s\n", buf);
+    n = sscanf(buf, "%[^0123456789]%d,%d,%d,%d,%d,%d",
+	junk, &h1, &h2, &h3, &h4, &p1, &p2);
+    if (n != 7 || p1 < 0 || p2 < 0 || p1 > 255 || p2 > 255) {
+	debug(38, 0, "Bad 227 reply\n");
+	debug(38, 0, "n=%d, p1=%d, p2=%d\n", n, p1, p2);
+	ftpSendPort(ftpState);
+	return;
+    }
+    sprintf(junk, "%d.%d.%d.%d", h1, h2, h3, h4);
+    if (!safe_inet_addr(junk, NULL)) {
+	debug(38, 0, "unsafe address (%s)\n", junk);
+	ftpSendPort(ftpState);
+	return;
+    }
+    port = ((p1 << 8) + p2);
+    debug(0, 0, "ftpReadPasv: connecting to %s, port %d\n", junk, port);
+    commConnectStart(fd, junk, port, ftpPasvCallback, ftpState);
+}
+
+static void
+ftpPasvCallback(int fd, int status, void *data)
+{
+    FtpStateData *ftpState = data;
+    debug(0, 0, "ftpPasvCallback\n");
+    if (status == COMM_ERROR) {
+	squid_error_entry(ftpState->entry, ERR_CONNECT_FAIL, xstrerror());
+	comm_close(fd);
+	return;
+    }
+    ftpRestOrList(ftpState);
+}
+
+static void
+ftpSendPort(FtpStateData * ftpState)
+{
+    debug(38, 1, "This is ftpSendPort\n");
+    EBIT_RESET(ftpState->flags, FTP_PASV_SUPPORTED);
+}
+
+static void
+ftpReadPort(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    debug(38, 1, "This is ftpReadPort\n");
+}
+
+static void
+ftpRestOrList(FtpStateData * ftpState)
+{
+    debug(38, 1, "This is ftpRestOrList\n");
+    if (EBIT_TEST(ftpState->flags, FTP_ISDIR)) {
+	sprintf(cbuf, "LIST\r\n");
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_LIST;
+    } else if (ftpState->restart_offset > 0) {
+	sprintf(cbuf, "REST\r\n");
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_REST;
+    } else {
+	assert(ftpState->filepath != NULL);
+	sprintf(cbuf, "RETR %s\r\n", ftpState->filepath);
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_RETR;
+    }
+}
+
+static void
+ftpReadRest(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    debug(38, 1, "This is ftpReadRest\n");
+    assert(ftpState->restart_offset > 0);
+    if (code == 350) {
+	assert(ftpState->filepath != NULL);
+	sprintf(cbuf, "RETR %s\r\n", ftpState->filepath);
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_RETR;
+    } else if (code > 0) {
+	debug(0, 0, "ftpReadRest: REST not supported\n");
+	EBIT_RESET(ftpState->flags, FTP_REST_SUPPORTED);
+    } else {
+	ftpFail(ftpState);
+    }
+}
+
+static void
+ftpReadList(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    debug(38, 1, "This is ftpReadList\n");
+    if (code == 150 || code == 125) {
+	ftpAppendSuccessHeader(ftpState);
+	commSetSelect(ftpState->data.fd,
 	    COMM_SELECT_READ,
-	    ftpServerClosed,
-	    NULL, 0);
-	ftpget_server_write = squid_to_ftpget[1];
-	ftpget_server_read = ftpget_to_squid[0];
-	slp.tv_sec = 0;
-	slp.tv_usec = 250000;
-	select(0, NULL, NULL, NULL, &slp);
-	return 0;
-    }
-    /* child */
-    /* give up all extra priviligies */
-    no_suid();
-    /* set up stdin,stdout */
-    dup2(squid_to_ftpget[0], 0);
-    dup2(ftpget_to_squid[1], 1);
-    dup2(fileno(debug_log), 2);
-    close(squid_to_ftpget[0]);
-    close(squid_to_ftpget[1]);
-    close(ftpget_to_squid[0]);
-    close(ftpget_to_squid[1]);
-    dup2(cfd, 3);		/* pass listening socket to ftpget */
-    /* inherit stdin,stdout,stderr */
-    for (cfd = 4; cfd <= Biggest_FD; cfd++)
-	(void) close(cfd);
-    sprintf(pbuf, "%d", ftpget_port);
-    execlp(ftpget, ftpget, "-S", pbuf, NULL);
-    debug(50, 0, "ftpInitialize: %s: %s\n", ftpget, xstrerror());
-    _exit(1);
-    return (1);			/* eliminate compiler warning */
+	    ftpReadData,
+	    ftpState,
+	    0);
+	ftpState->state = READING_DATA;
+	return;
+    } else if (!EBIT_TEST(ftpState->flags, FTP_TRIED_NLST)) {
+	EBIT_SET(ftpState->flags, FTP_TRIED_NLST);
+	sprintf(cbuf, "NLST\r\n");
+	ftpWriteCommand(cbuf, ftpState);
+	ftpState->state = SENT_NLST;
+    } else {
+	ftpFail(ftpState);
+	return;
+    }
+}
+
+static void
+ftpReadRetr(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    debug(38, 1, "This is ftpReadRetr\n");
+    if (code >= 100 && code < 200) {
+	debug(0, 0, "reading data channel\n");
+	ftpAppendSuccessHeader(ftpState);
+	commSetSelect(ftpState->data.fd,
+	    COMM_SELECT_READ,
+	    ftpReadData,
+	    ftpState,
+	    0);
+	ftpState->state = READING_DATA;
+    } else {
+	ftpFail(ftpState);
+    }
+}
+
+static void
+ftpReadTransferDone(FtpStateData * ftpState)
+{
+    int code = ftpState->ctrl.replycode;
+    debug(38, 1, "This is ftpReadTransferDone\n");
+    if (code != 226) {
+	debug(38, 1, "Got code %d after reading data, releasing entry\n");
+	storeReleaseRequest(ftpState->entry);
+    }
+}
+
+static void
+ftpDataTransferDone(FtpStateData * ftpState)
+{
+    assert(ftpState->data.fd >= 0);
+    comm_close(ftpState->data.fd);
+    ftpState->data.fd = -1;
+    sprintf(cbuf, "QUIT\r\n");
+    ftpWriteCommand(cbuf, ftpState);
+    ftpState->state = SENT_QUIT;
+}
+
+static void
+ftpReadQuit(FtpStateData * ftpState)
+{
+    comm_close(ftpState->ctrl.fd);
+}
+
+static void
+ftpFail(FtpStateData * ftpState)
+{
+    debug(0, 0, "ftpFail\n");
+    comm_close(ftpState->ctrl.fd);
+}
+
+static void
+ftpAppendSuccessHeader(FtpStateData * ftpState)
+{
+    char *mime_type = NULL;
+    char *mime_enc = NULL;
+    char *urlpath = ftpState->request->urlpath;
+    char *filename = NULL;
+    char *t = NULL;
+    StoreEntry *e = ftpState->entry;
+    if (EBIT_TEST(ftpState->flags, FTP_HTTP_HEADER_SENT))
+	return;
+    assert(e->mem_obj->e_current_len == 0);
+    filename = (t = strrchr(urlpath, '/')) ? t + 1 : urlpath;
+    if (EBIT_TEST(ftpState->flags, FTP_ISDIR)) {
+	mime_type = "text/html";
+    } else {
+	mime_type = mimeGetContentType(filename);
+	mime_enc = mimeGetContentEncoding(filename);
+    }
+    storeAppendPrintf(e, "HTTP/1.0 200 Gatewaying\r\n");
+    storeAppendPrintf(e, "Date: %s\r\n", mkrfc1123(squid_curtime));
+    storeAppendPrintf(e, "MIME-Version: 1.0\r\n");
+    storeAppendPrintf(e, "Server: Squid %s\r\n", version_string);
+    if (ftpState->size > 0)
+	storeAppendPrintf(e, "Content-Length: %d\r\n", ftpState->size);
+    if (mime_type)
+	storeAppendPrintf(e, "Content-Type: %s\r\n", mime_type);
+    if (mime_enc)
+	storeAppendPrintf(e, "Content-Encoding: %s\r\n", mime_enc);
+    if (ftpState->mdtm > 0)
+	storeAppendPrintf(e, "Last-Modified: %s\r\n", mkrfc1123(ftpState->mdtm));
+    storeAppendPrintf(e, "\r\n");
 }
