    ClientHttpRequest *http;
    MsgPipe::Pointer virgin;
    MsgPipe::Pointer adapted;

private:
    typedef enum { notifyNone, notifyOwner, notifyIcap } Notify;
    void stop(Notify notify);
    void freeVirgin();
    void freeAdapted();
    CBDATA_CLASS2(ICAPClientReqmodPrecache);
};

#endif /* SQUID_ICAPCLIENTSIDEHOOK_H */
