         addr = Config.Addrs.udp_incoming;
 
     vc->queue = new MemBuf;
-
     vc->msg = new MemBuf;
+    vc->busy = 1;
 
-    vc->fd = comm_open(SOCK_STREAM,
-                       IPPROTO_TCP,
-                       addr,
-                       COMM_NONBLOCKING,
-                       "DNS TCP Socket");
-
-    if (vc->fd < 0)
-        fatal("Could not create a DNS socket");
-
-    comm_add_close_handler(vc->fd, idnsVCClosed, vc);
+    Comm::Connection *conn = new Comm::Connection;
+    conn->local = addr;
+    conn->remote = nameservers[ns].S;
 
-    vc->busy = 1;
+    AsyncCall::Pointer call = commCbCall(78,3, "idnsInitVCConnected", CommConnectCbPtrFun(idnsInitVCConnected, vc));
 
-    commConnectStart(vc->fd, nameservers[ns].S.NtoA(buf,MAX_IPSTRLEN), nameservers[ns].S.GetPort(), idnsInitVCConnected, vc);
+    ConnectStateData *cs = new ConnectStateData(conn, call);
+    cs->host = xstrdup("DNS TCP Socket");
+    cs->connect();
 }
 
 static void
