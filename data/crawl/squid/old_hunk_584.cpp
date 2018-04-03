    }
    virtual bool isAccepting() const;
    virtual size_t bytesWanted(Range<size_t> const aRange, bool ignoreDelayPool = false) const;
    virtual void complete();
    virtual store_client_t storeClientType() const;
    virtual char const *getSerialisedMetaData();
