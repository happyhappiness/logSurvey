     r->handler = handler;
     r->data = data;
     cbdataLock(r->data);
-    if ((redirector = GetFirstAvailable()))
-	redirectDispatch(redirector, r);
-    else
-	Enqueue(r);
-}
-
-static void
-redirectorStateFree(int fd, void *data)
-{
-    redirector_t *r = data;
-    assert(r->fd == fd);
-    if (r->inbuf) {
-	memFree(MEM_8K_BUF, r->inbuf);
-	r->inbuf = NULL;
-    }
-    dlinkDelete(&r->link, &redirectors);
-    cbdataFree(r);
-    NRedirectorsOpen--;
-    if (NRedirectorsOpen == 0 && !shutting_down)
-	fatal_dump("All redirectors have exited!");
+    if ((fqdn = fqdncache_gethostbyaddr(r->client_addr, 0)) == NULL)
+	fqdn = dash_str;
+    snprintf(buf, 8192, "%s %s/%s %s %s\n",
+	r->orig_url,
+	inet_ntoa(r->client_addr),
+	fqdn,
+	r->client_ident,
+	r->method_s);
+    helperSubmit(redirectors, buf, redirectHandleReply, r);
 }
 
 void
-redirectOpenServers(void)
+redirectInit(void)
 {
-    char *prg = Config.Program.redirect;
-    char *short_prg;
-    char *short_prg2;
-    redirector_t *redirector;
-    int k;
-    int redirectsocket;
-    LOCAL_ARRAY(char, fd_note_buf, FD_DESC_SZ);
-    static int first_time = 0;
-    char *s;
-    char *args[2];
-    int x;
-
-    if (first_time == 0) {
-	memset(&redirectors, '\0', sizeof(redirectors));
-    }
-    assert(redirectors.head == NULL);
-    assert(redirectors.tail == NULL);
-    if (Config.Program.redirect == NULL)
+    static int init = 0;
+    safe_free(redirectors);
+    if (!Config.Program.redirect)
 	return;
-    NRedirectors = Config.redirectChildren;
-    debug(29, 1) ("redirectOpenServers: Starting %d '%s' processes\n",
-	NRedirectors, prg);
-    if ((s = strrchr(prg, '/')))
-	short_prg = xstrdup(s + 1);
-    else
-	short_prg = xstrdup(prg);
-    short_prg2 = xmalloc(strlen(s) + 3);
-    snprintf(short_prg2, strlen(s) + 3, "(%s)", short_prg);
-    for (k = 0; k < NRedirectors; k++) {
-	args[0] = short_prg2;
-	args[1] = NULL;
-	x = ipcCreate(IPC_TCP_SOCKET,
-	    prg,
-	    args,
-	    "redirector",
-	    &redirectsocket,
-	    &redirectsocket);
-	if (x < 0) {
-	    debug(29, 1) ("WARNING: Cannot run '%s' process.\n", prg);
-	    continue;
-	}
-	NRedirectorsOpen++;
-	redirector = xcalloc(1, sizeof(redirector_t));
-	cbdataAdd(redirector, MEM_NONE);
-	redirector->flags.alive = 1;
-	redirector->index = k;
-	redirector->fd = redirectsocket;
-	redirector->inbuf = memAllocate(MEM_8K_BUF);
-	redirector->size = 8192;
-	redirector->offset = 0;
-	snprintf(fd_note_buf, FD_DESC_SZ, "%s #%d",
-	    short_prg,
-	    redirector->index + 1);
-	fd_note(redirector->fd, fd_note_buf);
-	commSetNonBlocking(redirector->fd);
-	comm_add_close_handler(redirector->fd, redirectorStateFree, redirector);
-	debug(29, 3) ("redirectOpenServers: 'redirect_server' %d started\n",
-	    k);
-	dlinkAddTail(redirector, &redirector->link, &redirectors);
-    }
-    if (first_time == 0) {
-	first_time++;
-	memset(&RedirectStats, '\0', sizeof(RedirectStats));
+    redirectors = xcalloc(1, sizeof(*redirectors));
+    redirectors->id_name = "redirector";
+    wordlistAdd(&redirectors->cmdline, Config.Program.redirect);
+    redirectors->n_to_start = Config.redirectChildren;
+    redirectors->ipc_type = IPC_TCP_SOCKET;
+    helperOpenServers(redirectors);
+    if (!init) {
 	cachemgrRegister("redirector",
 	    "URL Redirector Stats",
 	    redirectStats, 0, 1);
     }
-    safe_free(short_prg);
-    safe_free(short_prg2);
-}
-
-static void
-redirectShutdown(redirector_t * r)
-{
-    if (!r->flags.alive)
-	return;
-    if (r->flags.closing)
-	return;
-    debug(29, 3) ("redirectShutdown: closing redirector #%d, FD %d\n",
-	r->index + 1, r->fd);
-    r->flags.shutdown = 1;
-    r->flags.busy = 1;
-    /*
-     * orphan the redirector, it will have to be freed when its done with
-     * the current request
-     */
-    dlinkDelete(&r->link, &redirectors);
+    init++;
 }
 
 void
-redirectShutdownServers(void *unused)
+redirectShutdown(void)
 {
-    dlink_node *n;
-    redirector_t *redirect = NULL;
-    if (Config.Program.redirect == NULL)
+    if (!redirectors)
 	return;
-    for (n = redirectors.head; n != NULL; n = n->next) {
-	redirect = n->data;
-	redirectShutdown(redirect);
-    }
-}
-
-void
-redirectStats(StoreEntry * sentry)
-{
-    int k;
-    storeAppendPrintf(sentry, "Redirector Statistics:\n");
-    storeAppendPrintf(sentry, "requests: %d\n",
-	RedirectStats.requests);
-    storeAppendPrintf(sentry, "replies: %d\n",
-	RedirectStats.replies);
-    storeAppendPrintf(sentry, "queue length: %d\n",
-	RedirectStats.queue_size);
-    storeAppendPrintf(sentry, "avg service time: %d msec\n",
-	RedirectStats.avg_svc_time);
-    storeAppendPrintf(sentry, "number of redirectors: %d\n",
-	NRedirectors);
-    storeAppendPrintf(sentry, "use histogram:\n");
-    for (k = 0; k < NRedirectors; k++) {
-	storeAppendPrintf(sentry, "    redirector #%d: %d (%d rewrites)\n",
-	    k + 1,
-	    RedirectStats.use_hist[k],
-	    RedirectStats.rewrites[k]);
-    }
+    helperShutdown(redirectors);
+    wordlistDestroy(&redirectors->cmdline);
 }
