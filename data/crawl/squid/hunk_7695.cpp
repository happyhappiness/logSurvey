     if ((t = strchr(redirector->inbuf, '\n'))) {
 	/* end of record found */
 	*t = '\0';
-	if (t == redirector->inbuf)
-	    r->handler(r->fd, r->orig_url);
-	else
-	    r->handler(r->fd, redirector->inbuf);
+	debug(29, 5, "redirectHandleRead: reply: '%s'\n", redirector->inbuf);
+	if (r->handler) {
+	    r->handler(r->data,
+		t == redirector->inbuf ? NULL : redirector->inbuf);
+	}
+	safe_free(r);
 	redirector->redirectState = NULL;
 	redirector->flags &= ~REDIRECT_FLAG_BUSY;
+	redirector->offset = 0;
+	n = ++RedirectStats.replies;
+	svc_time = tvSubMsec(redirector->dispatch_time, current_time);
+	if (n > REDIRECT_AV_FACTOR)
+	    n = REDIRECT_AV_FACTOR;
+	RedirectStats.avg_svc_time
+	    = (RedirectStats.avg_svc_time * (n - 1) + svc_time) / n;
     }
-    while ((r = Dequeue()) && (redirector = GetFirstAvailable()))
+    while ((redirector = GetFirstAvailable()) && (r = Dequeue()))
 	redirectDispatch(redirector, r);
     return 0;
 }
 
-void redirectStart(url, fd, handler)
-     char *url;
-     int fd;
-     RH handler;
-{
-    redirectStateData *r = NULL;
-    redirector_t *redirector = NULL;
-
-    if (!handler)
-	fatal_dump("redirectStart: NULL handler");
-    r = xcalloc(1, sizeof(redirectStateData));
-    r->fd = fd;
-    r->orig_url = url;
-    r->handler = handler;
-    if ((redirector = GetFirstAvailable()))
-	redirectDispatch(redirector, r);
-    else
-	Enqueue(r);
-}
-
 static void Enqueue(r)
      redirectStateData *r;
 {
     struct redirectQueueData *new = xcalloc(1, sizeof(struct redirectQueueData));
     new->redirectState = r;
     *redirectQueueTailP = new;
     redirectQueueTailP = &new->next;
+    RedirectStats.queue_size++;
 }
 
 static redirectStateData *Dequeue()
