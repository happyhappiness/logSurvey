  */
 
 /*
- * ServerStateData is a class for common elements of Server-side modules
- * such as http.cc and ftp.cc.  It was invented to make ICAP code simpler.
+ * ServerStateData is a common base for server-side classes such as
+ * HttpStateData and FtpStateData. All such classes must be able to
+ * consume request bodies from the client-side or ICAP producer, adapt
+ * virgin responses using ICAP, and provide the client-side consumer with
+ * responses.
+ *
+ * TODO: Rename to ServerStateDataInfoRecordHandler.
  */
 
+
 #ifndef SQUID_SERVER_H
 #define SQUID_SERVER_H
 
 #include "StoreIOBuffer.h"
 #include "forward.h"
+#include "BodyPipe.h"
 
 #if ICAP_CLIENT
 #include "ICAP/ICAPServiceRep.h"
-
-class ICAPClientRespmodPrecache;
+#include "ICAP/ICAPInitiator.h"
+#include "ICAP/ICAPModXact.h"
 
 class ICAPAccessCheck;
 #endif
 
-class ServerStateData
+class ServerStateData:
+#if ICAP_CLIENT
+    public ICAPInitiator,
+    public BodyProducer,
+#endif
+    public BodyConsumer
 {
 
 public:
     ServerStateData(FwdState *);
     virtual ~ServerStateData();
 
+    // returns primary or "request data connection" fd
+    virtual int dataDescriptor() const = 0; 
+
+    // BodyConsumer: consume request body or adapted response body.
+    // The implementation just calls the corresponding HTTP or ICAP handle*()
+    // method, depending on the pipe.
+    virtual void noteMoreBodyDataAvailable(BodyPipe &);
+    virtual void noteBodyProductionEnded(BodyPipe &);
+    virtual void noteBodyProducerAborted(BodyPipe &);
+
+    // read response data from the network
+    virtual void maybeReadVirginBody() = 0;
+
+    // abnormal transaction termination; reason is for debugging only
+    virtual void abortTransaction(const char *reason) = 0;
+
 #if ICAP_CLIENT
-    virtual bool takeAdaptedHeaders(HttpReply *) = 0;
-    virtual bool takeAdaptedBody(MemBuf *) = 0;
-    virtual void finishAdapting() = 0;
-    virtual void abortAdapting() = 0;
-    virtual void icapSpaceAvailable() = 0;
     virtual void icapAclCheckDone(ICAPServiceRep::Pointer) = 0;
+
+    // ICAPInitiator: start an ICAP transaction and receive adapted headers.
+    virtual void noteIcapHeadersAdapted();
+    virtual void noteIcapHeadersAborted();
+
+    // BodyProducer: provide virgin response body to ICAP.
+    virtual void noteMoreBodySpaceAvailable(BodyPipe &);
+    virtual void noteBodyConsumerAborted(BodyPipe &);
 #endif
 
-public:
-    // should be protected
+public: // should be protected
+    void serverComplete(); // call when no server communication is expected
+
+protected:
+    // kids customize these
+    virtual void haveParsedReplyHeaders(); // default does nothing
+    virtual void completeForwarding(); // default calls fwd->complete()
+
+    // BodyConsumer for HTTP: consume request body.
+    void handleMoreRequestBodyAvailable();
+    void handleRequestBodyProductionEnded();
+    virtual void handleRequestBodyProducerAborted() = 0;
+
+    // sending of the request body to the server
+    void sendMoreRequestBody();
+    // has body; kids overwrite to increment I/O stats counters
+    virtual void sentRequestBody(int fd, size_t size, comm_err_t errflag) = 0;
+    virtual void doneSendingRequestBody() = 0;
+    static IOCB sentRequestBodyWrapper;
+
+    virtual void closeServer() = 0; // end communication with the server
+    virtual bool doneWithServer() const = 0; // did we end communication?
+
+    // Entry-dependent callbacks use this check to quit if the entry went bad
+    bool abortOnBadEntry(const char *abortReason);
+
+#if ICAP_CLIENT
+    bool startIcap(ICAPServiceRep::Pointer, HttpRequest *cause);
+    void cleanIcap();
+    virtual bool doneWithIcap() const; // did we end ICAP communication?
+
+    // BodyConsumer for ICAP: consume adapted response body.
+    void handleMoreAdaptedBodyAvailable();
+    void handleAdaptedBodyProductionEnded();
+    void handleAdaptedBodyProducerAborted();
+
+    void handleIcapCompleted();
+    void handleIcapAborted();
+#endif
+
+public: // should not be
     StoreEntry *entry;
     FwdState::Pointer fwd;
     HttpRequest *request;
     HttpReply *reply;
 
 protected:
+    BodyPipe::Pointer requestBodySource; // to consume request body
+    IOCB *requestSender; // set if we are expecting comm_write to call us back
+
 #if ICAP_CLIENT
+    BodyPipe::Pointer virginBodyDestination; // to provide virgin response body
+    ICAPModXact::Pointer adaptedHeadSource; // to get adapted response headers
+    BodyPipe::Pointer adaptedBodySource; // to consume adated response body
 
-    ICAPClientRespmodPrecache *icap;
     bool icapAccessCheckPending;
-    bool startIcap(ICAPServiceRep::Pointer);
 #endif
 
+private:
+    void quitIfAllDone(); // successful termination
+    
 };
 
 #endif /* SQUID_SERVER_H */
