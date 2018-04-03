  */
 void FtpStateData::ftpAcceptDataConnection(const CommAcceptCbParams &io)
 {
-    char ntoapeer[MAX_IPSTRLEN];
-    debugs(9, 3, "ftpAcceptDataConnection");
-
-    // one connection accepted. the handler has stopped listening. drop our local pointer to it.
-    data.listener = NULL;
+    debugs(9, 3, HERE);
 
     if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
         abortTransaction("entry aborted when accepting data conn");
         return;
     }
 
+    if (io.flag != COMM_OK) {
+        data.close();
+        debugs(9, DBG_IMPORTANT, "FTP AcceptDataConnection: FD " << io.fd << ": " << xstrerr(io.xerrno));
+        /** \todo Need to send error message on control channel*/
+        ftpFail(this);
+        return;
+    }
+
+    /* data listening conn is no longer even open. abort. */
+    if (data.fd <= 0 || fd_table[data.fd].flags.open == 0) {
+        data.clear(); // ensure that it's cleared and not just closed.
+        return;
+    }
+
     /** \par
      * When squid.conf ftp_sanitycheck is enabled, check the new connection is actually being
      * made by the remote client which is connected to the FTP control socket.
+     * Or the one which we were told to listen for by control channel messages (may differ under NAT).
      * This prevents third-party hacks, but also third-party load balancing handshakes.
      */
     if (Config.Ftp.sanitycheck) {
+        char ntoapeer[MAX_IPSTRLEN];
         io.details.peer.NtoA(ntoapeer,MAX_IPSTRLEN);
 
-        if (strcmp(fd_table[ctrl.fd].ipaddr, ntoapeer) != 0) {
+        if (strcmp(fd_table[ctrl.fd].ipaddr, ntoapeer) != 0 &&
+                strcmp(fd_table[data.fd].ipaddr, ntoapeer) != 0) {
             debugs(9, DBG_IMPORTANT,
                    "FTP data connection from unexpected server (" <<
                    io.details.peer << "), expecting " <<
-                   fd_table[ctrl.fd].ipaddr);
+                   fd_table[ctrl.fd].ipaddr << " or " << fd_table[data.fd].ipaddr);
 
-            /* close the bad soures connection down ASAP. */
+            /* close the bad sources connection down ASAP. */
             comm_close(io.nfd);
 
-            /* we are ony accepting once, so need to re-open the listener socket. */
-            typedef CommCbMemFunT<FtpStateData, CommAcceptCbParams> acceptDialer;
-            AsyncCall::Pointer acceptCall = JobCallback(11, 5,
-                                            acceptDialer, this, FtpStateData::ftpAcceptDataConnection);
-            data.listener = new Comm::ListenStateData(data.fd, acceptCall, false);
+            /* drop the bad connection (io) by ignoring the attempt. */
             return;
         }
     }
 
-    if (io.flag != COMM_OK) {
-        debugs(9, DBG_IMPORTANT, "ftpHandleDataAccept: FD " << io.nfd << ": " << xstrerr(io.xerrno));
-        /** \todo XXX Need to set error message */
-        ftpFail(this);
-        return;
-    }
-
     /**\par
-     * Replace the Listen socket with the accepted data socket */
+     * Replace the Listening socket with the accepted data socket */
     data.close();
     data.opened(io.nfd, dataCloser());
     data.port = io.details.peer.GetPort();
-    io.details.peer.NtoA(data.host,SQUIDHOSTNAMELEN);
+    data.host = xstrdup(fd_table[io.nfd].ipaddr);
 
     debugs(9, 3, "ftpAcceptDataConnection: Connected data socket on " <<
            "FD " << io.nfd << " to " << io.details.peer << " FD table says: " <<
            "ctrl-peer= " << fd_table[ctrl.fd].ipaddr << ", " <<
            "data-peer= " << fd_table[data.fd].ipaddr);
 
+    assert(haveControlChannel("ftpAcceptDataConnection"));
+    assert(ctrl.message == NULL);
 
-    AsyncCall::Pointer nullCall = NULL;
-    commSetTimeout(ctrl.fd, -1, nullCall);
-
-    typedef CommCbMemFunT<FtpStateData, CommTimeoutCbParams> TimeoutDialer;
-    AsyncCall::Pointer timeoutCall =  JobCallback(9, 5,
-                                      TimeoutDialer, this, FtpStateData::ftpTimeout);
-    commSetTimeout(data.fd, Config.Timeout.read, timeoutCall);
-
-    /*\todo XXX We should have a flag to track connect state...
-     *    host NULL -> not connected, port == local port
-     *    host set  -> connected, port == remote port
-     */
-    /* Restart state (SENT_NLST/LIST/RETR) */
-    FTP_SM_FUNCS[state] (this);
+    // Ctrl channel operations will determine what happens to this data connection
 }
 
 /// \ingroup ServerProtocolFTPInternal
