     virtual ~Xaction();
 
     void disableRetries();
+    void disableRepeats(const char *reason);
+    bool retriable() const { return isRetriable; }
+    bool repeatable() const { return isRepeatable; }
 
     // comm handler wrappers, treat as private
     void noteCommConnected(const CommConnectCbParams &io);
