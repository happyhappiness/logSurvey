    Clients theClients; // all clients waiting for a call back

    ICAPOptions *theOptions;
    time_t theLastUpdate; // time the options were last updated

    static const int TheSessionFailureLimit;
    int theSessionFailures;
    const char *isSuspended; // also stores suspension reason for debugging

    bool waiting;   // for an OPTIONS transaction to finish
    bool notifying; // may be true in any state except for the initial
    bool updateScheduled; // time-based options update has been scheduled

private:
    ICAP::Method parseMethod(const char *) const;
    ICAP::VectPoint parseVectPoint(const char *) const;

    void suspend(const char *reason);

    bool hasOptions() const;
    bool needNewOptions() const;

    void scheduleUpdate();
    void scheduleNotification();

    void startGettingOptions();
    void changeOptions(ICAPOptions *newOptions);
    void checkOptions();

    void announceStatusChange(const char *downPhrase, bool important) const;

    const char *status() const;

    Pointer self;
    mutable bool wasAnnouncedUp; // prevent sequential same-state announcements
    CBDATA_CLASS2(ICAPServiceRep);
};

