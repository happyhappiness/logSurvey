     void handle204NoContent();
     void handleUnknownScode();
 
+    void bypassFailure();
+
+    void startSending();
+    void disableBypass(const char *reason);
+
+    void prepEchoing();
     void echoMore();
 
     virtual bool doneAll() const;
