 helperDispatch(helper_server * srv, Helper::Request * r)
 {
     helper *hlp = srv->parent;
-    Helper::Request **ptr = NULL;
-    unsigned int slot;
+    const uint64_t reqId = ++srv->nextRequestId;
 
     if (!cbdataReferenceValid(r->data)) {
         debugs(84, DBG_IMPORTANT, "helperDispatch: invalid callback data");
         delete r;
         return;
     }
 
-    for (slot = 0; slot < (hlp->childs.concurrency ? hlp->childs.concurrency : 1); ++slot) {
-        if (!srv->requests[slot]) {
-            ptr = &srv->requests[slot];
-            break;
-        }
-    }
-
-    assert(ptr);
-    *ptr = r;
+    r->Id = reqId;
+    helper_server::Requests::iterator it = srv->requests.insert(srv->requests.end(), r);
     r->dispatch_time = current_time;
 
     if (srv->wqueue->isNull())
         srv->wqueue->init();
 
-    if (hlp->childs.concurrency)
-        srv->wqueue->Printf("%d %s", slot, r->buf);
-    else
+    if (hlp->childs.concurrency) {
+        srv->requestsIndex.insert(helper_server::RequestIndex::value_type(reqId, it));
+        assert(srv->requestsIndex.size() == srv->requests.size());
+        srv->wqueue->Printf("%" PRIu64 " %s", reqId, r->buf);
+    } else
         srv->wqueue->append(r->buf, strlen(r->buf));
 
     if (!srv->flags.writing) {
