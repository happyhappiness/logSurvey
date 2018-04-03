    Clients theClients; // all clients waiting for a call back

    ICAPOptions *theOptions;

    typedef enum { stateInit, stateWait, stateUp, stateDown } State;
    State theState;
    bool notifying; // may be true in any state except for the initial

private:
    ICAP::Method parseMethod(const char *) const;
    ICAP::VectPoint parseVectPoint(const char *) const;

    bool waiting() const;
    bool needNewOptions() const;

    void scheduleNotification();
    void changeOptions(ICAPOptions *newOptions);
    void startGettingOptions();
    void scheduleUpdate();

    const char *status() const;

    Pointer self;
    CBDATA_CLASS2(ICAPServiceRep);
};

