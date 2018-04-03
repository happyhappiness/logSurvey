
    virtual void closeServer() = 0;            /**< end communication with the server */
    virtual bool doneWithServer() const = 0;   /**< did we end communication? */
    /// whether we may receive more virgin response body bytes
    virtual bool mayReadVirginReplyBody() const = 0;

    /// Entry-dependent callbacks use this check to quit if the entry went bad
    bool abortOnBadEntry(const char *abortReason);
