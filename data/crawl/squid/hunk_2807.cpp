     mustStop("commClosed");
 }
 
+bool
+Mgr::Inquirer::aggregate(Ipc::Response::Pointer aResponse)
+{
+    Mgr::Response& response = static_cast<Response&>(*aResponse);
+    if (response.hasAction())
+        aggrAction->add(response.getAction());
+    return true;
+}
+
 void
-Mgr::Inquirer::swanSong()
+Mgr::Inquirer::sendResponse()
 {
-    debugs(16, 5, HERE);
-    removeTimeoutEvent();
-    if (requestId > 0) {
-        DequeueRequest(requestId);
-        requestId = 0;
-    }
     if (aggrAction->aggregatable()) {
         removeCloseHandler();
         AsyncJob::Start(new ActionWriter(aggrAction, fd));
         fd = -1; // should not close fd because we passed it to ActionWriter
     }
-    close();
 }
 
 bool
 Mgr::Inquirer::doneAll() const
 {
-    return !writer && pos == strands.end();
-}
-
-/// returns and forgets the right Inquirer callback for strand request
-AsyncCall::Pointer
-Mgr::Inquirer::DequeueRequest(unsigned int requestId)
-{
-    debugs(16, 3, HERE << " requestId " << requestId);
-    Must(requestId != 0);
-    AsyncCall::Pointer call;
-    RequestsMap::iterator request = TheRequestsMap.find(requestId);
-    if (request != TheRequestsMap.end()) {
-        call = request->second;
-        Must(call != NULL);
-        TheRequestsMap.erase(request);
-    }
-    return call;
-}
-
-void
-Mgr::Inquirer::HandleRemoteAck(const Mgr::Response& response)
-{
-    Must(response.requestId != 0);
-    AsyncCall::Pointer call = DequeueRequest(response.requestId);
-    if (call != NULL) {
-        HandleAckDialer* dialer = dynamic_cast<HandleAckDialer*>(call->getDialer());
-        Must(dialer);
-        dialer->arg1 = response;
-        ScheduleCallHere(call);
-    }
-}
-
-/// called when we are no longer waiting for the strand to respond
-void
-Mgr::Inquirer::removeTimeoutEvent()
-{
-    if (eventFind(&Inquirer::RequestTimedOut, this))
-        eventDelete(&Inquirer::RequestTimedOut, this);
-}
-
-/// Mgr::Inquirer::requestTimedOut wrapper
-void
-Mgr::Inquirer::RequestTimedOut(void* param)
-{
-    debugs(16, 3, HERE);
-    Must(param != NULL);
-    Inquirer* cmi = static_cast<Inquirer*>(param);
-    // use async call to enable job call protection that time events lack
-    CallJobHere(16, 5, cmi, Mgr::Inquirer, requestTimedOut);
-}
-
-/// called when the strand failed to respond (or finish responding) in time
-void
-Mgr::Inquirer::requestTimedOut()
-{
-    debugs(16, 3, HERE);
-    if (requestId != 0) {
-        DequeueRequest(requestId);
-        requestId = 0;
-        Must(!done()); // or we should not be called
-        ++pos; // advance after a failed inquiry
-        inquire();
-    }
-}
-
-const char*
-Mgr::Inquirer::status() const
-{
-    static MemBuf buf;
-    buf.reset();
-    buf.Printf(" [FD %d, requestId %u]", fd, requestId);
-    buf.terminate();
-    return buf.content();
+    return !writer && Ipc::Inquirer::doneAll();
 }
