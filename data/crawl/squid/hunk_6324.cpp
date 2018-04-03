 static void
 fqdncacheEnqueue(fqdncache_entry * f)
 {
+    static time_t last_warning = 0;
     struct fqdncacheQueueData *new = xcalloc(1, sizeof(struct fqdncacheQueueData));
     new->f = f;
     *fqdncacheQueueTailP = new;
     fqdncacheQueueTailP = &new->next;
+    queue_length++;
+    if (queue_length < NDnsServersAlloc)
+	return;
+    if (squid_curtime - last_warning < 600)
+	return;
+    last_warning = squid_curtime;
+    debug(35, 0) ("fqdncacheEnqueue: WARNING: All dnsservers are busy.\n");
+    debug(35, 0) ("fqdncacheEnqueue: WARNING: %d DNS lookups queued\n", queue_length);
+    if (queue_length > NDnsServersAlloc * 2)
+	fatal("Too many queued DNS lookups");
+    if (Config.dnsChildren >= DefaultDnsChildrenMax)
+	return;
+    debug(35, 1) ("fqdncacheEnqueue: Consider increasing 'dns_children' in your config file.\n");
 }
 
 static void *
