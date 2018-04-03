
    virtual void closeServer() = 0;            /**< end communication with the server */
    virtual bool doneWithServer() const = 0;   /**< did we end communication? */

    /// Entry-dependent callbacks use this check to quit if the entry went bad
    bool abortOnBadEntry(const char *abortReason);
