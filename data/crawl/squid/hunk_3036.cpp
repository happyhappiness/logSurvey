     void truncateVirginBody();
 
     virtual void haveParsedReplyHeaders();
+    virtual bool getMoreRequestBody(MemBuf &buf);
     virtual void closeServer(); // end communication with the server
     virtual bool doneWithServer() const; // did we end communication?
     virtual void abortTransaction(const char *reason); // abnormal termination
