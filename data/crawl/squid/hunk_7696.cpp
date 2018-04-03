      redirectStateData *r;
 {
     char *buf = NULL;
+    int len;
+    if (r->handler == NULL) {
+	debug(29, 1, "redirectDispatch: skipping '%s' because no handler\n",
+	    r->orig_url);
+	safe_free(r);
+	return;
+    }
     redirect->flags |= REDIRECT_FLAG_BUSY;
     redirect->redirectState = r;
+    redirect->dispatch_time = current_time;
+    len = strlen(r->orig_url) + 1;
+    buf = xmalloc(len + 1);
+    sprintf(buf, "%s\n", r->orig_url);
     comm_write(redirect->fd,
-	xstrdup(buf),
-	strlen(buf),
+	buf,
+	len,
 	0,			/* timeout */
 	NULL,			/* Handler */
 	NULL);			/* Handler-data */
-    debug(14, 5, "redirectDispatch: Request sent to Redirector #%d.\n",
-	redirect->index + 1);
+    debug(29, 5, "redirectDispatch: Request sent to Redirector #%d, %d bytes\n",
+	redirect->index + 1, len);
+    RedirectStats.use_hist[redirect->index]++;
+    RedirectStats.requests++;
 }
 
 
+/**** PUBLIC FUNCTIONS ****/
+
+
+void redirectStart(url, fd, handler, data)
+     char *url;
+     int fd;
+     RH handler;
+     void *data;
+{
+    redirectStateData *r = NULL;
+    redirector_t *redirector = NULL;
+    if (!handler)
+	fatal_dump("redirectStart: NULL handler");
+    if (!do_redirect) {
+	(*handler) (data, NULL);
+	return;
+    }
+    r = xcalloc(1, sizeof(redirectStateData));
+    r->fd = fd;
+    r->orig_url = url;
+    r->handler = handler;
+    r->data = data;
+    if ((redirector = GetFirstAvailable()))
+	redirectDispatch(redirector, r);
+    else
+	Enqueue(r);
+}
+
 void redirectOpenServers()
 {
     char *prg = getRedirectProgram();
     int k;
     int redirectsocket;
     static char fd_note_buf[FD_ASCII_NOTE_SZ];
+    static int first_time = 0;
 
+    if (!do_redirect)
+	return;
     /* free old structures if present */
     if (redirect_child_table) {
 	for (k = 0; k < NRedirectors; k++)
