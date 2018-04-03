 	return (-1.0 * dpercent(s - c, c));
 }
 
+static void
+statClientRequests(StoreEntry * s)
+{
+    dlink_node *i;
+    clientHttpRequest *http;
+    ConnStateData *conn;
+    StoreEntry *e;
+    int fd;
+    for (i = ClientActiveRequests.head; i; i = i->next) {
+	http = i->data;
+	assert(http);
+	conn = http->conn;
+	storeAppendPrintf(s, "Connection: %p\n", conn);
+	if (conn) {
+	    fd = conn->fd;
+	    storeAppendPrintf(s, "\tFD %d, read %d, wrote %d\n", fd,
+		fd_table[fd].bytes_read, fd_table[fd].bytes_written);
+	    storeAppendPrintf(s, "\tFD desc: %s\n", fd_table[fd].desc);
+	    storeAppendPrintf(s, "\tin: buf %p, offset %d, size %d\n",
+		conn->in.buf, conn->in.offset, conn->in.size);
+	    storeAppendPrintf(s, "\tpeer: %s:%d\n",
+		inet_ntoa(conn->peer.sin_addr),
+		ntohs(conn->peer.sin_port));
+	    storeAppendPrintf(s, "\tme: %s:%d\n",
+		inet_ntoa(conn->me.sin_addr),
+		ntohs(conn->me.sin_port));
+	    storeAppendPrintf(s, "\tnrequests: %d\n",
+		conn->nrequests);
+	    storeAppendPrintf(s, "\tpersistent: %d\n",
+		conn->persistent);
+	    storeAppendPrintf(s, "\tdefer: n %d, until %d\n",
+		conn->defer.n, conn->defer.until);
+	}
+	storeAppendPrintf(s, "uri %s\n", http->uri);
+	storeAppendPrintf(s, "out.offset %d, out.size %d\n",
+	    http->out.offset, http->out.size);
+	storeAppendPrintf(s, "req_sz %d\n", http->req_sz);
+	e = http->entry;
+	storeAppendPrintf(s, "entry %p/%s\n", e, e ? storeKeyText(e->key) : "N/A");
+	e = http->old_entry;
+	storeAppendPrintf(s, "old_entry %p/%s\n", e, e ? storeKeyText(e->key) : "N/A");
+	storeAppendPrintf(s, "start %d.%06d (%f seconds ago)\n", http->start.tv_sec,
+	    http->start.tv_usec,
+	    tvSubDsec(http->start, current_time));
+	storeAppendPrintf(s, "\n");
+    }
+}
+
 #if STAT_GRAPHS
 /*
  * urgh, i don't like these, but they do cut the amount of code down immensely
