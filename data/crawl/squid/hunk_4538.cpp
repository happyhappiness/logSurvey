     virtual void abortTransaction(const char *reason) = 0;
 
 #if ICAP_CLIENT
-    virtual void icapAclCheckDone(ICAPServiceRep::Pointer) = 0;
+    void icapAclCheckDone(ICAPServiceRep::Pointer);
+    // a hack to reach HttpStateData::orignal_request
+    virtual  HttpRequest *originalRequest();
 
     // ICAPInitiator: start an ICAP transaction and receive adapted headers.
     virtual void noteIcapAnswer(HttpMsg *message);
