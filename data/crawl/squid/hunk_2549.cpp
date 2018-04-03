 static void
 idnsInitVC(int ns)
 {
-    char buf[MAX_IPSTRLEN];
-
     nsvc *vc = cbdataAlloc(nsvc);
     assert(ns < nns);
+    assert(vc->conn == NULL); // MUST be NULL from the construction process!
     nameservers[ns].vc = vc;
     vc->ns = ns;
-
-    Ip::Address addr;
-
-    if (!Config.Addrs.udp_outgoing.IsNoAddr())
-        addr = Config.Addrs.udp_outgoing;
-    else
-        addr = Config.Addrs.udp_incoming;
-
-    if (nameservers[ns].S.IsIPv4() && !addr.SetIPv4()) {
-        debugs(31, DBG_CRITICAL, "ERROR: Cannot contact DNS nameserver " << nameservers[ns].S << " from " << addr);
-        addr.SetAnyAddr();
-        addr.SetIPv4();
-    }
-
     vc->queue = new MemBuf;
-
     vc->msg = new MemBuf;
+    vc->busy = 1;
 
-    vc->fd = comm_open(SOCK_STREAM,
-                       IPPROTO_TCP,
-                       addr,
-                       COMM_NONBLOCKING,
-                       "DNS TCP Socket");
+    Comm::ConnectionPointer conn = new Comm::Connection();
 
-    if (vc->fd < 0)
-        fatal("Could not create a DNS socket");
+    if (!Config.Addrs.udp_outgoing.IsNoAddr())
+        conn->local = Config.Addrs.udp_outgoing;
+    else
+        conn->local = Config.Addrs.udp_incoming;
 
-    comm_add_close_handler(vc->fd, idnsVCClosed, vc);
+    conn->remote = nameservers[ns].S;
 
-    vc->busy = 1;
+    AsyncCall::Pointer call = commCbCall(78,3, "idnsInitVCConnected", CommConnectCbPtrFun(idnsInitVCConnected, vc));
 
-    commConnectStart(vc->fd, nameservers[ns].S.NtoA(buf,MAX_IPSTRLEN), nameservers[ns].S.GetPort(), idnsInitVCConnected, vc);
+    Comm::ConnOpener *cs = new Comm::ConnOpener(conn, call, Config.Timeout.connect);
+    cs->setHost("DNS TCP Socket");
+    AsyncJob::Start(cs);
 }
 
 static void
