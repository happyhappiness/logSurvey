     }
 
     if (virginBodyEndReached(virginBodySending)) {
-        debugs(93, 5, "ICAPModXact echoed all" << status());
+        debugs(93, 5, HERE << "echoed all" << status());
         stopSending(true);
     } else {
-        debugs(93, 5, "ICAPModXact has " <<
+        debugs(93, 5, HERE << "has " <<
                virgin.body_pipe->buf().contentSize() << " bytes " <<
                "and expects more to echo" << status());
         // TODO: timeout if virgin or adapted pipes are broken
     }
 }
 
-bool ICAPModXact::doneSending() const
+bool Adaptation::Icap::ModXact::doneSending() const
 {
     return state.sending == State::sendingDone;
 }
 
 // stop (or do not start) sending adapted message body
-void ICAPModXact::stopSending(bool nicely)
+void Adaptation::Icap::ModXact::stopSending(bool nicely)
 {
     if (doneSending())
         return;
 
     if (state.sending != State::sendingUndecided) {
-        debugs(93, 7, "ICAPModXact will no longer send" << status());
+        debugs(93, 7, HERE << "will no longer send" << status());
         if (adapted.body_pipe != NULL) {
             virginBodySending.disable();
             // we may leave debts if we were echoing and the virgin
