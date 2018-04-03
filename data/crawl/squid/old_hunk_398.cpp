    virtual bool getMoreRequestBody(MemBuf &buf);
    virtual void closeServer(); // end communication with the server
    virtual bool doneWithServer() const; // did we end communication?
    virtual void abortTransaction(const char *reason); // abnormal termination
    virtual bool mayReadVirginReplyBody() const;

    /**
     * determine if read buffer can have space made available
     * for a read.
