     xfree(sbuf);
 }
 
-const Comm::ConnectionPointer &
-FtpStateData::dataConnection() const
-{
-    return data.conn;
-}
-
-void
-FtpStateData::dataComplete()
-{
-    debugs(9, 3,HERE);
-
-    /* Connection closed; transfer done. */
-
-    /// Close data channel, if any, to conserve resources while we wait.
-    data.close();
-
-    /* expect the "transfer complete" message on the control socket */
-    /*
-     * DPW 2007-04-23
-     * Previously, this was the only place where we set the
-     * 'buffered_ok' flag when calling scheduleReadControlReply().
-     * It caused some problems if the FTP server returns an unexpected
-     * status code after the data command.  FtpStateData was being
-     * deleted in the middle of dataRead().
-     */
-    /* AYJ: 2011-01-13: Bug 2581.
-     * 226 status is possibly waiting in the ctrl buffer.
-     * The connection will hang if we DONT send buffered_ok.
-     * This happens on all transfers which can be completly sent by the
-     * server before the 150 started status message is read in by Squid.
-     * ie all transfers of about one packet hang.
-     */
-    scheduleReadControlReply(1);
-}
-
-void
-FtpStateData::maybeReadVirginBody()
-{
-    // too late to read
-    if (!Comm::IsConnOpen(data.conn) || fd_table[data.conn->fd].closing())
-        return;
-
-    if (data.read_pending)
-        return;
-
-    const int read_sz = replyBodySpace(*data.readBuf, 0);
-
-    debugs(11,9, HERE << "FTP may read up to " << read_sz << " bytes");
-
-    if (read_sz < 2)	// see http.cc
-        return;
-
-    data.read_pending = true;
-
-    typedef CommCbMemFunT<FtpStateData, CommTimeoutCbParams> TimeoutDialer;
-    AsyncCall::Pointer timeoutCall =  JobCallback(9, 5,
-                                      TimeoutDialer, this, FtpStateData::ftpTimeout);
-    commSetConnTimeout(data.conn, Config.Timeout.read, timeoutCall);
-
-    debugs(9,5,HERE << "queueing read on FD " << data.conn->fd);
-
-    typedef CommCbMemFunT<FtpStateData, CommIoCbParams> Dialer;
-    entry->delayAwareRead(data.conn, data.readBuf->space(), read_sz,
-                          JobCallback(9, 5, Dialer, this, FtpStateData::dataRead));
-}
-
-void
-FtpStateData::dataRead(const CommIoCbParams &io)
-{
-    int j;
-    int bin;
-
-    data.read_pending = false;
-
-    debugs(9, 3, HERE << "ftpDataRead: FD " << io.fd << " Read " << io.size << " bytes");
-
-    if (io.size > 0) {
-        kb_incr(&(statCounter.server.all.kbytes_in), io.size);
-        kb_incr(&(statCounter.server.ftp.kbytes_in), io.size);
-    }
-
-    if (io.flag == Comm::ERR_CLOSING)
-        return;
-
-    assert(io.fd == data.conn->fd);
-
-    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
-        abortTransaction("entry aborted during dataRead");
-        return;
-    }
-
-    if (io.flag == Comm::OK && io.size > 0) {
-        debugs(9,5,HERE << "appended " << io.size << " bytes to readBuf");
-        data.readBuf->appended(io.size);
-#if USE_DELAY_POOLS
-        DelayId delayId = entry->mem_obj->mostBytesAllowed();
-        delayId.bytesIn(io.size);
-#endif
-        ++ IOStats.Ftp.reads;
-
-        for (j = io.size - 1, bin = 0; j; ++bin)
-            j >>= 1;
-
-        ++ IOStats.Ftp.read_hist[bin];
-    }
-
-    if (io.flag != Comm::OK) {
-        debugs(50, ignoreErrno(io.xerrno) ? 3 : DBG_IMPORTANT,
-               "ftpDataRead: read error: " << xstrerr(io.xerrno));
-
-        if (ignoreErrno(io.xerrno)) {
-            typedef CommCbMemFunT<FtpStateData, CommTimeoutCbParams> TimeoutDialer;
-            AsyncCall::Pointer timeoutCall = JobCallback(9, 5,
-                                             TimeoutDialer, this, FtpStateData::ftpTimeout);
-            commSetConnTimeout(io.conn, Config.Timeout.read, timeoutCall);
-
-            maybeReadVirginBody();
-        } else {
-            failed(ERR_READ_ERROR, 0);
-            /* failed closes ctrl.conn and frees ftpState */
-            return;
-        }
-    } else if (io.size == 0) {
-        debugs(9,3, HERE << "Calling dataComplete() because io.size == 0");
-        /*
-         * DPW 2007-04-23
-         * Dangerous curves ahead.  This call to dataComplete was
-         * calling scheduleReadControlReply, handleControlReply,
-         * and then ftpReadTransferDone.  If ftpReadTransferDone
-         * gets unexpected status code, it closes down the control
-         * socket and our FtpStateData object gets destroyed.   As
-         * a workaround we no longer set the 'buffered_ok' flag in
-         * the scheduleReadControlReply call.
-         */
-        dataComplete();
-    }
-
-    processReplyBody();
-}
-
 void
-FtpStateData::processReplyBody()
+Ftp::Gateway::processReplyBody()
 {
-    debugs(9, 3, HERE << "FtpStateData::processReplyBody starting.");
+    debugs(9, 3, status());
 
     if (request->method == Http::METHOD_HEAD && (flags.isdir || theSize != -1)) {
         serverComplete();
