     virtual void closeServer(); // end communication with the server
     virtual bool doneWithServer() const; // did we end communication?
     virtual void abortTransaction(const char *reason); // abnormal termination
+    virtual bool mayReadVirginReplyBody() const;
 
     // consuming request body
     virtual void handleMoreRequestBodyAvailable();
