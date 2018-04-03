    bool abortOnBadEntry(const char *abortReason);

#if USE_ADAPTATION
    bool startAdaptation(Adaptation::ServicePointer service, HttpRequest *cause);
    void adaptVirginReplyBody(const char *buf, ssize_t len);
    void cleanAdaptation();
    virtual bool doneWithAdaptation() const;   /**< did we end ICAP communication? */
