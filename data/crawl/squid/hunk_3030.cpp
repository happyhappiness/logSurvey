      */
 
     /* Accept a new connection */
-    Connection *newConnDetails = new Connection();
-    int newfd = oldAccept(*newConnDetails);
+    ConnectionPointer newConnDetails = new Connection();
+    comm_err_t status = oldAccept(newConnDetails);
 
     /* Check for errors */
-    if (newfd < 0) {
+    if (!newConnDetails->isOpen()) {
 
-        if (newfd == COMM_NOMESSAGE) {
+        if (status == COMM_NOMESSAGE) {
             /* register interest again */
-            debugs(5, 5, HERE << "try later: FD " << conn->fd << " handler: " << callName);
+            debugs(5, 5, HERE << "try later: " << conn << " handler: " << theCallSub);
             commSetSelect(conn->fd, COMM_SELECT_READ, doAccept, this, 0);
             return;
         }
 
         // A non-recoverable error; notify the caller */
-        debugs(5, 5, HERE << "non-recoverable error: FD " << conn->fd << " handler: " << callName);
-        notify(-1, COMM_ERROR, newConnDetails);
-        mayAcceptMore = false;
+        debugs(5, 5, HERE << "non-recoverable error: " << conn << " handler: " << theCallSub);
+        notify(status, newConnDetails);
+        mustStop("Listener socket closed");
         return;
     }
 
-    debugs(5, 5, HERE << "accepted: FD " << conn->fd <<
-           " newfd: " << newfd << " from: " << newConnDetails->remote <<
-           " handler: " << callName);
-    notify(newfd, COMM_OK, newConnDetails);
+    debugs(5, 5, HERE << "Listener: " << conn <<
+           " accepted new connection " << newConnDetails <<
+           " handler: " << theCallSub);
+    notify(status, newConnDetails);
 }
 
 void
 Comm::ConnAcceptor::acceptNext()
 {
     Must(IsConnOpen(conn));
-    debugs(5, 2, HERE << "connection on FD " << conn->fd);
+    debugs(5, 2, HERE << "connection on " << conn);
     acceptOne();
 }
 
+// NP: can't be a const function because syncWithComm() side effects hit theCallSub->callback().
 void
-Comm::ConnAcceptor::notify(int newfd, comm_err_t flag, const Comm::ConnectionPointer &newConnDetails)
+Comm::ConnAcceptor::notify(comm_err_t flag, const Comm::ConnectionPointer &newConnDetails)
 {
     // listener socket handlers just abandon the port with COMM_ERR_CLOSING
     // it should only happen when this object is deleted...
     if (flag == COMM_ERR_CLOSING) {
         return;
     }
 
-    if (callDialer != NULL) {
-        AsyncCall::Pointer call = commCbCall(callSection, callLevel, callName, *callDialer);
-        typedef CommAcceptCbParams Params;
-        Params &params = GetCommParams<Params>(call);
+    if (theCallSub != NULL) {
+        AsyncCall::Pointer call = theCallSub->callback();
+        CommAcceptCbParams &params = GetCommParams<CommAcceptCbParams>(call);
         params.fd = conn->fd;
-        params.nfd = newfd;
-        params.details = newConnDetails;
+        params.conn = newConnDetails;
         params.flag = flag;
         params.xerrno = errcode;
         ScheduleCallHere(call);
     }
-    else if (theCallback != NULL) {
-        typedef CommAcceptCbParams Params;
-        Params &params = GetCommParams<Params>(theCallback);
-        params.fd = conn->fd;
-        params.nfd = newfd;
-        params.details = newConnDetails;
-        params.flag = flag;
-        params.xerrno = errcode;
-        ScheduleCallHere(theCallback);
-        // only permit the call to be scheduled once.
-        mayAcceptMore = false;
-        theCallback = NULL;
-    }
 }
 
 /**
  * accept() and process
- * Wait for an incoming connection on FD.
+ * Wait for an incoming connection on our listener socket.
+ *
+ * \retval COMM_OK         success. details parameter filled.
+ * \retval COMM_NOMESSAGE  attempted accept() but nothing useful came in.
+ * \retval COMM_ERROR      an outright failure occured.
+ *                         Or if this client has too many connections already.
  */
-int
-Comm::ConnAcceptor::oldAccept(Comm::Connection &details)
+comm_err_t
+Comm::ConnAcceptor::oldAccept(Comm::ConnectionPointer &details)
 {
     PROF_start(comm_accept);
     statCounter.syscalls.sock.accepts++;
     int sock;
     struct addrinfo *gai = NULL;
-    details.local.InitAddrInfo(gai);
+    details->local.InitAddrInfo(gai);
 
     errcode = 0; // reset local errno copy.
     if ((sock = accept(conn->fd, gai->ai_addr, &gai->ai_addrlen)) < 0) {
         errcode = errno; // store last accept errno locally.
 
-        details.local.FreeAddrInfo(gai);
+        details->local.FreeAddrInfo(gai);
 
         PROF_stop(comm_accept);
 
         if (ignoreErrno(errno)) {
-            debugs(50, 5, HERE << "FD " << conn->fd << ": " << xstrerror());
+            debugs(50, 5, HERE << conn << ": " << xstrerror());
             return COMM_NOMESSAGE;
         } else if (ENFILE == errno || EMFILE == errno) {
-            debugs(50, 3, HERE << "FD " << conn->fd << ": " << xstrerror());
+            debugs(50, 3, HERE << conn << ": " << xstrerror());
             return COMM_ERROR;
         } else {
-            debugs(50, 1, HERE << "FD " << conn->fd << ": " << xstrerror());
+            debugs(50, 1, HERE << conn << ": " << xstrerror());
             return COMM_ERROR;
         }
     }
 
     Must(sock >= 0);
-    details.fd = sock;
-    details.remote = *gai;
+    details->fd = sock;
+    details->remote = *gai;
 
     if ( Config.client_ip_max_connections >= 0) {
-        if (clientdbEstablished(details.remote, 0) > Config.client_ip_max_connections) {
-            debugs(50, DBG_IMPORTANT, "WARNING: " << details.remote << " attempting more than " << Config.client_ip_max_connections << " connections.");
-            details.local.FreeAddrInfo(gai);
+        if (clientdbEstablished(details->remote, 0) > Config.client_ip_max_connections) {
+            debugs(50, DBG_IMPORTANT, "WARNING: " << details->remote << " attempting more than " << Config.client_ip_max_connections << " connections.");
+            details->local.FreeAddrInfo(gai);
             return COMM_ERROR;
         }
     }
 
     // lookup the local-end details of this new connection
-    details.local.InitAddrInfo(gai);
-    details.local.SetEmpty();
+    details->local.InitAddrInfo(gai);
+    details->local.SetEmpty();
     getsockname(sock, gai->ai_addr, &gai->ai_addrlen);
-    details.local = *gai;
-    details.local.FreeAddrInfo(gai);
+    details->local = *gai;
+    details->local.FreeAddrInfo(gai);
 
     /* fdstat update */
-    // XXX : these are not all HTTP requests. use a note about type and ip:port details.
+    // XXX : these are not all HTTP requests. use a note about type and ip:port details->
     // so we end up with a uniform "(HTTP|FTP-data|HTTPS|...) remote-ip:remote-port"
     fd_open(sock, FD_SOCKET, "HTTP Request");
 
     fdd_table[sock].close_file = NULL;
     fdd_table[sock].close_line = 0;
 
     fde *F = &fd_table[sock];
-    details.remote.NtoA(F->ipaddr,MAX_IPSTRLEN);
-    F->remote_port = details.remote.GetPort();
-    F->local_addr = details.local;
-    F->sock_family = details.local.IsIPv6()?AF_INET6:AF_INET;
+    details->remote.NtoA(F->ipaddr,MAX_IPSTRLEN);
+    F->remote_port = details->remote.GetPort();
+    F->local_addr = details->local;
+    F->sock_family = details->local.IsIPv6()?AF_INET6:AF_INET;
 
     // set socket flags
     commSetCloseOnExec(sock);
