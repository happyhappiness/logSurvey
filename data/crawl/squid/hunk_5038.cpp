     event_queued = 1;
 }
 
+static void idnsDoSendQueryVC(nsvc *vc);
+
+static void
+idnsSentQueryVC(int fd, char *buf, size_t size, comm_err_t flag, void *data)
+{
+    nsvc * vc = (nsvc *)data;
+
+    if (flag == COMM_ERR_CLOSING)
+        return;
+
+    if (flag != COMM_OK || size <= 0) {
+        comm_close(fd);
+        return;
+    }
+
+    vc->busy = 0;
+    idnsDoSendQueryVC(vc);
+}
+
+static void
+idnsDoSendQueryVC(nsvc *vc)
+{
+    if (vc->busy)
+        return;
+
+    if (vc->queue.size == 0)
+        return;
+
+    MemBuf mb = vc->queue;
+
+    vc->queue = MemBufNULL;
+
+    vc->busy = 1;
+
+    commSetTimeout(vc->fd, Config.Timeout.idns_query, NULL, NULL);
+
+    comm_old_write_mbuf(vc->fd, mb, idnsSentQueryVC, vc);
+}
+
+static void
+idnsInitVCConnected(int fd, comm_err_t status, int xerrno, void *data)
+{
+    nsvc * vc = (nsvc *)data;
+
+    if (status != COMM_OK) {
+        comm_close(fd);
+        return;
+    }
+
+    comm_read(fd, (char *)&vc->msglen, 2 , idnsReadVCHeader, vc);
+    vc->busy = 0;
+    idnsDoSendQueryVC(vc);
+}
+
+static void
+idnsVCClosed(int fd, void *data)
+{
+    nsvc * vc = (nsvc *)data;
+    nameservers[vc->ns].vc = NULL;
+}
+
+static void
+idnsInitVC(int ns)
+{
+    nsvc *vc = cbdataAlloc(nsvc);
+    nameservers[ns].vc = vc;
+
+    struct IN_ADDR addr;
+
+    if (Config.Addrs.udp_outgoing.s_addr != no_addr.s_addr)
+        addr = Config.Addrs.udp_outgoing;
+    else
+        addr = Config.Addrs.udp_incoming;
+
+    vc->queue = MemBufNULL;
+
+    vc->msg = MemBufNULL;
+
+    vc->fd = comm_open(SOCK_STREAM,
+                       IPPROTO_TCP,
+                       addr,
+                       0,
+                       COMM_NONBLOCKING,
+                       "DNS Socket");
+
+    if (vc->fd < 0)
+        fatal("Could not create a DNS socket");
+
+    comm_add_close_handler(vc->fd, idnsVCClosed, vc);
+
+    vc->busy = 1;
+
+    commConnectStart(vc->fd, inet_ntoa(nameservers[ns].S.sin_addr), ntohs(nameservers[ns].S.sin_port), idnsInitVCConnected, vc);
+}
+
+static void
+idnsSendQueryVC(idns_query * q, int ns)
+{
+    if (nameservers[ns].vc == NULL)
+        idnsInitVC(ns);
+
+    nsvc *vc = nameservers[ns].vc;
+
+    if (memBufIsNull(&vc->queue))
+        memBufDefInit(&vc->queue);
+
+    short head = htons(q->sz);
+
+    memBufAppend(&vc->queue, (char *)&head, 2);
+
+    memBufAppend(&vc->queue, q->buf, q->sz);
+
+    idnsDoSendQueryVC(vc);
+}
+
 static void
 idnsSendQuery(idns_query * q)
 {
