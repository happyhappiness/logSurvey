 
     fwd = NULL; // refcounted
 
+    if (requestBodySource != NULL)
+        requestBodySource->clearConsumer();
+
+#if ICAP_CLIENT
+    cleanIcap();
+#endif
+}
+
+// called when no more server communication is expected; may quit
+void
+ServerStateData::serverComplete()
+{
+    debugs(11,5,HERE << "serverComplete " << this);
+
+    if (!doneWithServer()) {
+        closeServer();
+        assert(doneWithServer());
+    }
+
+    if (requestBodySource != NULL)
+        stopConsumingFrom(requestBodySource);
+
+#if ICAP_CLIENT
+    if (virginBodyDestination != NULL)
+        stopProducingFor(virginBodyDestination, true);
+
+    if (!doneWithIcap())
+        return;
+#endif
+
+    completeForwarding();
+    quitIfAllDone();
+}
+
+// When we are done talking to the primary server, we may be still talking 
+// to the ICAP service. And vice versa. Here, we quit only if we are done
+// talking to both.
+void ServerStateData::quitIfAllDone() {
+#if ICAP_CLIENT
+    if (!doneWithIcap()) {
+        debugs(11,5, HERE << "transaction not done: still talking to ICAP");
+        return;
+    }
+#endif
+
+    if (!doneWithServer()) {
+        debugs(11,5, HERE << "transaction not done: still talking to server");
+        return;
+    }
+
+    debugs(11,3, HERE << "transaction done");
+    delete this;
+}
+
+// FTP side overloads this to work around multiple calls to fwd->complete
+void
+ServerStateData::completeForwarding() {
+    debugs(11,5, HERE << "completing forwarding for "  << fwd);
+    assert(fwd != NULL);
+    fwd->complete();
+}
+
+// Entry-dependent callbacks use this check to quit if the entry went bad
+bool
+ServerStateData::abortOnBadEntry(const char *abortReason)
+{
+    if (entry->isAccepting())
+        return false;
+
+    debugs(11,5, HERE << "entry is not Accepting!");
+    abortTransaction(abortReason);
+    return true;
+}
+
+// more request or adapted response body is available
+void
+ServerStateData::noteMoreBodyDataAvailable(BodyPipe &bp)
+{
+#if ICAP_CLIENT
+    if (adaptedBodySource == &bp) {
+        handleMoreAdaptedBodyAvailable();
+        return;
+    }
+#endif
+    handleMoreRequestBodyAvailable();
+}
+
+// the entire request or adapted response body was provided, successfully
+void
+ServerStateData::noteBodyProductionEnded(BodyPipe &bp)
+{
 #if ICAP_CLIENT
-    if (icap) {
-        debug(11,5)("ServerStateData destroying icap=%p\n", icap);
-        icap->ownerAbort();
-        delete icap;
+    if (adaptedBodySource == &bp) {
+        handleAdaptedBodyProductionEnded();
+        return;
     }
 #endif
+    handleRequestBodyProductionEnded();
+}
+
+// premature end of the request or adapted response body production
+void
+ServerStateData::noteBodyProducerAborted(BodyPipe &bp)
+{
+#if ICAP_CLIENT
+    if (adaptedBodySource == &bp) {
+        handleAdaptedBodyProducerAborted();
+        return;
+    }
+#endif
+    handleRequestBodyProducerAborted();
+}
+
+
+// more origin request body data is available
+void
+ServerStateData::handleMoreRequestBodyAvailable()
+{
+    if (!requestSender)
+        sendMoreRequestBody();
+    else
+        debugs(9,3, HERE << "waiting for request body write to complete");
+}
+
+// there will be no more handleMoreRequestBodyAvailable calls
+void
+ServerStateData::handleRequestBodyProductionEnded()
+{
+    if (!requestSender)
+        doneSendingRequestBody();
+    else
+        debugs(9,3, HERE << "waiting for request body write to complete");
+}
+
+// called when we are done sending request body; kids extend this
+void
+ServerStateData::doneSendingRequestBody() {
+    debugs(9,3, HERE << "done sending request body");
+    assert(requestBodySource != NULL);
+    stopConsumingFrom(requestBodySource);
+
+    // kids extend this
+}
+
+// called when body producers aborts; kids extend this
+void
+ServerStateData::handleRequestBodyProducerAborted()
+{
+    if (requestSender != NULL)
+        debugs(9,3, HERE << "fyi: request body aborted while we were sending");
+
+    stopConsumingFrom(requestBodySource); // requestSender, if any, will notice
+
+    // kids extend this
+}
+
+void
+ServerStateData::sentRequestBodyWrapper(int fd, char *bufnotused, size_t size, comm_err_t errflag, int xerrno, void *data)
+{
+    ServerStateData *server = static_cast<ServerStateData *>(data);
+    server->sentRequestBody(fd, size, errflag);
+}
+
+// called when we wrote request headers(!) or a part of the body
+void
+ServerStateData::sentRequestBody(int fd, size_t size, comm_err_t errflag)
+{
+    debug(11, 5) ("sentRequestBody: FD %d: size %d: errflag %d.\n",
+                  fd, (int) size, errflag);
+    debugs(32,3,HERE << "sentRequestBody called");
+
+    requestSender = NULL;
+
+    if (size > 0) {
+        fd_bytes(fd, size, FD_WRITE);
+        kb_incr(&statCounter.server.all.kbytes_out, size);
+        // kids should increment their counters
+    }
+
+    if (errflag == COMM_ERR_CLOSING)
+        return;
+
+    if (!requestBodySource) {
+        debugs(9,3, HERE << "detected while-we-were-sending abort");
+        return; // do nothing;
+    }
+
+    if (errflag) {
+        debug(11, 1) ("sentRequestBody error: FD %d: %s\n", fd, xstrerr(errno));
+        ErrorState *err;
+        err = errorCon(ERR_WRITE_ERROR, HTTP_BAD_GATEWAY, fwd->request);
+        err->xerrno = errno;
+        fwd->fail(err);
+        abortTransaction("I/O error while sending request body");
+        return;
+    }
+
+    if (EBIT_TEST(entry->flags, ENTRY_ABORTED)) {
+        abortTransaction("store entry aborted while sending request body");
+        return;
+    }
+
+    if (requestBodySource->exhausted())
+        doneSendingRequestBody();
+    else
+        sendMoreRequestBody();
 }
 
+void
+ServerStateData::sendMoreRequestBody()
+{
+    assert(requestBodySource != NULL);
+    assert(!requestSender);
+    MemBuf buf;
+    if (requestBodySource->getMoreData(buf)) {
+        debugs(9,3, HERE << "will write " << buf.contentSize() << " request body bytes");
+        requestSender = &ServerStateData::sentRequestBodyWrapper;
+        comm_write_mbuf(dataDescriptor(), &buf, requestSender, this);
+    } else {
+        debugs(9,3, HERE << "will wait for more request body bytes or eof");
+        requestSender = NULL;
+    }
+}
+
+// called by noteIcapHeadersAdapted(), HTTP server overwrites this
+void
+ServerStateData::haveParsedReplyHeaders()
+{
+    // default does nothing
+}
+
+
 #if ICAP_CLIENT
 /*
  * Initiate an ICAP transaction.  Return true on success.
  * Caller will handle error condition by generating a Squid error message
  * or take other action.
  */
 bool
-ServerStateData::startIcap(ICAPServiceRep::Pointer service)
+ServerStateData::startIcap(ICAPServiceRep::Pointer service, HttpRequest *cause)
 {
     debug(11,5)("ServerStateData::startIcap() called\n");
     if (!service) {
