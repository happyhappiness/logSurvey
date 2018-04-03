 }
 
 void
-Mgr::Forwarder::start()
+Mgr::Forwarder::handleError()
 {
-    debugs(16, 3, HERE);
-    entry->registerAbort(&Forwarder::Abort, this);
-
-    typedef NullaryMemFunT<Mgr::Forwarder> Dialer;
-    AsyncCall::Pointer callback = JobCallback(16, 5, Dialer, this,
-                                  Forwarder::handleRemoteAck);
-    if (++LastRequestId == 0) // don't use zero value as requestId
-        ++LastRequestId;
-    requestId = LastRequestId;
-    TheRequestsMap[requestId] = callback;
-    Request mgrRequest(KidIdentifier, requestId, fd, params);
-    Ipc::TypedMsgHdr message;
-
-    try {
-        mgrRequest.pack(message);
-    } catch (...) {
-        // assume the pack() call failed because the message did not fit
-        // TODO: add a more specific exception?
-        debugs(16, DBG_CRITICAL, "ERROR: uri " << entry->url() << " exceeds buffer size");
-        quitOnError("long URI", errorCon(ERR_INVALID_URL, HTTP_REQUEST_URI_TOO_LARGE, request));
-    }
-
-    Ipc::SendMessage(Ipc::coordinatorAddr, message);
-    const double timeout = 10; // in seconds
-    eventAdd("Mgr::Forwarder::requestTimedOut", &Forwarder::RequestTimedOut,
-             this, timeout, 0, false);
+    debugs(16, DBG_CRITICAL, "ERROR: uri " << entry->url() << " exceeds buffer size");
+    sendError(errorCon(ERR_INVALID_URL, HTTP_REQUEST_URI_TOO_LARGE, httpRequest));
+    mustStop("long URI");
 }
 
 void
-Mgr::Forwarder::swanSong()
+Mgr::Forwarder::handleTimeout()
 {
-    debugs(16, 5, HERE);
-    removeTimeoutEvent();
-    if (requestId > 0) {
-        DequeueRequest(requestId);
-        requestId = 0;
-    }
-    close();
+    sendError(errorCon(ERR_LIFETIME_EXP, HTTP_REQUEST_TIMEOUT, httpRequest));
+    Ipc::Forwarder::handleTimeout();
 }
 
-bool
-Mgr::Forwarder::doneAll() const
+void
+Mgr::Forwarder::handleException(const std::exception& e)
 {
-    debugs(16, 5, HERE);
-    return requestId == 0;
+    if (entry != NULL && httpRequest != NULL && fd >= 0)
+        sendError(errorCon(ERR_INVALID_RESP, HTTP_INTERNAL_SERVER_ERROR, httpRequest));
+    Ipc::Forwarder::handleException(e);
 }
 
 /// called when the client socket gets closed by some external force
 void
-Mgr::Forwarder::noteCommClosed(const CommCloseCbParams &io)
+Mgr::Forwarder::noteCommClosed(const CommCloseCbParams& params)
 {
     debugs(16, 5, HERE);
-    Must(fd == io.fd);
+    Must(fd == params.fd);
     fd = -1;
     mustStop("commClosed");
 }
