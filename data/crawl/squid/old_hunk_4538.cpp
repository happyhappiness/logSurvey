    virtual void abortTransaction(const char *reason) = 0;

#if ICAP_CLIENT
    virtual void icapAclCheckDone(ICAPServiceRep::Pointer) = 0;

    // ICAPInitiator: start an ICAP transaction and receive adapted headers.
    virtual void noteIcapAnswer(HttpMsg *message);
