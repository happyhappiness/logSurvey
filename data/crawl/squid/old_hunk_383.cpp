    virtual void maybeReadVirginBody() = 0;

    /// abnormal transaction termination; reason is for debugging only
    virtual void abortTransaction(const char *reason) = 0;

    /// a hack to reach HttpStateData::orignal_request
    virtual  HttpRequest *originalRequest();
