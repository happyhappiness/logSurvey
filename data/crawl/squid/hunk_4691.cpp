 
     bool done() const;
     virtual bool doneAll() const;
-    virtual void doStop();
     void mustStop(const char *reason);
 
+    // called just before the 'done' transaction is deleted
+    virtual void swanSong(); 
+
     // returns a temporary string depicting transaction status, for debugging
     const char *status() const;
     virtual void fillPendingStatus(MemBuf &buf) const;
