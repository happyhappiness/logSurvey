     srv->stats.pending += 1;
     r->dispatch_time = current_time;
 
-    if (memBufIsNull(srv->wqueue))
-        memBufDefInit(srv->wqueue);
+    if (srv->wqueue->isNull())
+        srv->wqueue->init();
 
     if (hlp->concurrency)
-        memBufPrintf(srv->wqueue, "%d %s", slot, r->buf);
+        srv->wqueue->Printf("%d %s", slot, r->buf);
     else
-        memBufAppend(srv->wqueue, r->buf, strlen(r->buf));
+        srv->wqueue->append(r->buf, strlen(r->buf));
 
     if (!srv->flags.writing) {
         assert(NULL == srv->writebuf);
