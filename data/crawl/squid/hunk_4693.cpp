         debug(11,3)("ServerStateData::startIcap fails: broken service\n");
         return false;
     }
-    assert(NULL == icap);
-    icap = new ICAPClientRespmodPrecache(service);
+
+    // check whether we should be sending a body as well
+    assert(!virginBodyDestination);
+    assert(!reply->body_pipe);
+    // start body pipe to feed ICAP transaction if needed
+    ssize_t size = 0;
+    if (reply->expectingBody(cause->method, size) && size) {
+        virginBodyDestination = new BodyPipe(this);
+        reply->body_pipe = virginBodyDestination;
+        debugs(93, 6, HERE << "will send virgin reply body to " << 
+            virginBodyDestination << "; size: " << size);
+    }
+
+    adaptedHeadSource = new ICAPModXact(this, reply, cause, service);
+    ICAPModXact::AsyncStart(adaptedHeadSource.getRaw());
     return true;
 }
 
+// properly cleans up ICAP-related state
+// may be called multiple times
+void ServerStateData::cleanIcap() {
+    debugs(11,5, HERE << "cleaning ICAP");
+
+    if (virginBodyDestination != NULL)
+        stopProducingFor(virginBodyDestination, false);
+
+    if (adaptedHeadSource != NULL) {
+        AsyncCall(11,5, adaptedHeadSource.getRaw(), ICAPModXact::noteInitiatorAborted);
+        adaptedHeadSource = NULL;
+    }
+
+    if (adaptedBodySource != NULL)
+        stopConsumingFrom(adaptedBodySource);
+
+    assert(doneWithIcap()); // make sure the two methods are in sync
+}
+
+bool
+ServerStateData::doneWithIcap() const {
+    return !virginBodyDestination && !adaptedHeadSource && !adaptedBodySource;
+}
+
+// can supply more virgin response body data
+void
+ServerStateData::noteMoreBodySpaceAvailable(BodyPipe &)
+{
+    maybeReadVirginBody();
+}
+
+// the consumer of our virgin response body aborted, we should too
+void
+ServerStateData::noteBodyConsumerAborted(BodyPipe &bp)
+{
+    stopProducingFor(virginBodyDestination, false);
+    handleIcapAborted();
+}
+
+// received adapted response headers (body may follow)
+void
+ServerStateData::noteIcapHeadersAdapted()
+{
+    // extract and lock reply before (adaptedHeadSource = NULL) can destroy it
+    HttpReply *rep = dynamic_cast<HttpReply*>(adaptedHeadSource->adapted.header);
+    HTTPMSGLOCK(rep);
+    adaptedHeadSource = NULL; // we do not expect any more messages from it
+
+    if (abortOnBadEntry("entry went bad while waiting for adapted headers")) {
+        HTTPMSGUNLOCK(rep); // hopefully still safe, even if "this" is deleted
+        return;
+    }
+
+    assert(rep);
+    entry->replaceHttpReply(rep);
+    HTTPMSGUNLOCK(reply);
+
+    reply = rep; // already HTTPMSGLOCKed above
+
+    haveParsedReplyHeaders();
+
+    assert(!adaptedBodySource);
+    if (reply->body_pipe != NULL) {
+        // subscribe to receive adapted body
+        adaptedBodySource = reply->body_pipe;
+        // assume that ICAP does not auto-consume on failures
+        assert(adaptedBodySource->setConsumerIfNotLate(this));
+    } else {
+        // no body
+        handleIcapCompleted();
+    }
+
+}
+
+// will not receive adapted response headers (and, hence, body)
+void
+ServerStateData::noteIcapHeadersAborted()
+{
+    adaptedHeadSource = NULL;
+    handleIcapAborted();
+}
+
+// more adapted response body is available
+void
+ServerStateData::handleMoreAdaptedBodyAvailable()
+{
+    const size_t contentSize = adaptedBodySource->buf().contentSize();
+
+    debugs(11,5, HERE << "consuming " << contentSize << " bytes of adapted " <<
+           "response body at offset " << adaptedBodySource->consumedSize());
+
+    if (abortOnBadEntry("entry refuses adapted body"))
+        return;
+
+    assert(entry);
+    BodyPipeCheckout bpc(*adaptedBodySource);
+    const StoreIOBuffer ioBuf(&bpc.buf, bpc.offset);
+    entry->write(ioBuf);
+    bpc.buf.consume(contentSize);
+    bpc.checkIn();
+}
+
+// the entire adapted response body was produced, successfully
+void
+ServerStateData::handleAdaptedBodyProductionEnded()
+{
+    stopConsumingFrom(adaptedBodySource);
+
+    if (abortOnBadEntry("entry went bad while waiting for adapted body eof"))
+        return;
+
+    handleIcapCompleted();
+}
+
+// premature end of the adapted response body
+void ServerStateData::handleAdaptedBodyProducerAborted()
+{
+    stopConsumingFrom(adaptedBodySource);
+    handleIcapAborted();
+}
+
+// common part of noteIcapHeadersAdapted and handleAdaptedBodyProductionEnded
+void
+ServerStateData::handleIcapCompleted()
+{
+    debugs(11,5, HERE << "handleIcapCompleted");
+    cleanIcap();
+    completeForwarding();
+    quitIfAllDone();
+}
+
+// common part of noteIcap*Aborted and noteBodyConsumerAborted methods
+void
+ServerStateData::handleIcapAborted()
+{
+    debugs(11,5, HERE << "handleIcapAborted; entry empty: " << entry->isEmpty());
+
+    if (abortOnBadEntry("entry went bad while ICAP aborted"))
+        return;
+
+    if (entry->isEmpty()) {
+        debugs(11,9, HERE << "creating ICAP error entry after ICAP failure");
+        ErrorState *err =
+            errorCon(ERR_ICAP_FAILURE, HTTP_INTERNAL_SERVER_ERROR, request);
+        err->xerrno = errno;
+        fwd->fail(err);
+        fwd->dontRetry(true);
+    }
+
+    debugs(11,5, HERE << "bailing after ICAP failure");
+
+    cleanIcap();
+    closeServer();
+    quitIfAllDone();
+}
+
 #endif
