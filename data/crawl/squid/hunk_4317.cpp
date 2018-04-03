     // Entry-dependent callbacks use this check to quit if the entry went bad
     bool abortOnBadEntry(const char *abortReason);
 
-#if ICAP_CLIENT
-    bool startIcap(ICAPServiceRep::Pointer, HttpRequest *cause);
+#if USE_ADAPTATION
+    bool startAdaptation(Adaptation::ServicePointer service, HttpRequest *cause);
     void adaptVirginReplyBody(const char *buf, ssize_t len);
-    void cleanIcap();
-    virtual bool doneWithIcap() const; // did we end ICAP communication?
+    void cleanAdaptation();
+    virtual bool doneWithAdaptation() const; // did we end ICAP communication?
 
     // BodyConsumer for ICAP: consume adapted response body.
     void handleMoreAdaptedBodyAvailable();
     void handleAdaptedBodyProductionEnded();
     void handleAdaptedBodyProducerAborted();
 
-    void handleIcapCompleted();
-    void handleIcapAborted(bool bypassable = false);
+    void handleAdaptationCompleted();
+    void handleAdaptationAborted(bool bypassable = false);
 #endif
 
 protected:
