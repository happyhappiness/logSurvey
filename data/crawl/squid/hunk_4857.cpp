     ClientHttpRequest *http;
     MsgPipe::Pointer virgin;
     MsgPipe::Pointer adapted;
+    BodyReader::Pointer body_reader;
 
 private:
     typedef enum { notifyNone, notifyOwner, notifyIcap } Notify;
     void stop(Notify notify);
     void freeVirgin();
     void freeAdapted();
     CBDATA_CLASS2(ICAPClientReqmodPrecache);
+
+    // Hooks to BodyReader so HttpStateData can get the
+    // adapted request body
+    static BodyReadFunc readBody;
+    static BodyAbortFunc abortBody;
+    static BodyKickFunc kickBody;
 };
 
 #endif /* SQUID_ICAPCLIENTSIDEHOOK_H */
