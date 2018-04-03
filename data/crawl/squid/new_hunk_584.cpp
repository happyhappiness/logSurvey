    }
    virtual bool isAccepting() const;
    virtual size_t bytesWanted(Range<size_t> const aRange, bool ignoreDelayPool = false) const;
    /// flags [truncated or too big] entry with ENTRY_BAD_LENGTH and releases it
    void lengthWentBad(const char *reason);
    virtual void complete();
    virtual store_client_t storeClientType() const;
    virtual char const *getSerialisedMetaData();
