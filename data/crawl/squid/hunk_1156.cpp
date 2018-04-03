         callback(data, nilReply);
         return;
     }
+    hlp->prepSubmit();
+    hlp->submit(buf, callback, data);
+}
+
+bool
+helper::queueFull() const {
+    return stats.queue_size > static_cast<int>(childs.queue_size);
+}
+
+/// prepares the helper for request submission via trySubmit() or helperSubmit()
+/// currently maintains full_time and kills Squid if the helper remains full for too long
+void
+helper::prepSubmit()
+{
+    if (!queueFull())
+        full_time = 0;
+    else if (!full_time) // may happen here if reconfigure decreases capacity
+        full_time = squid_curtime;
+    else if (squid_curtime - full_time > 180)
+        fatalf("Too many queued %s requests", id_name);
+}
+
+bool
+helper::trySubmit(const char *buf, HLPCB * callback, void *data)
+{
+    prepSubmit();
 
+    if (queueFull()) {
+        debugs(84, DBG_IMPORTANT, id_name << " drops request due to a full queue");
+        return false; // request was ignored
+    }
+
+    submit(buf, callback, data); // will send or queue
+    return true; // request submitted or queued
+}
+
+/// dispatches or enqueues a helper requests; does not enforce queue limits
+void
+helper::submit(const char *buf, HLPCB * callback, void *data)
+{
     Helper::Request *r = new Helper::Request(callback, data, buf);
     helper_server *srv;
 
-    if ((srv = GetFirstAvailable(hlp)))
+    if ((srv = GetFirstAvailable(this)))
         helperDispatch(srv, r);
     else
-        Enqueue(hlp, r);
+        Enqueue(this, r);
 
     debugs(84, DBG_DATA, Raw("buf", buf, strlen(buf)));
+
+    if (!queueFull()) {
+        full_time = 0;
+    } else if (!full_time) {
+        debugs(84, 3, id_name << " queue became full");
+        full_time = squid_curtime;
+    }
 }
 
 /// lastserver = "server last used as part of a reserved request sequence"
