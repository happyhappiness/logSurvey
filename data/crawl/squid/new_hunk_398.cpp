    virtual bool getMoreRequestBody(MemBuf &buf);
    virtual void closeServer(); // end communication with the server
    virtual bool doneWithServer() const; // did we end communication?
    virtual void abortAll(const char *reason); // abnormal termination
    virtual bool mayReadVirginReplyBody() const;

    void abortTransaction(const char *reason) { abortAll(reason); } // abnormal termination

    /**
     * determine if read buffer can have space made available
     * for a read.
