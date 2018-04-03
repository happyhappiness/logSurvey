    AsyncCall::Pointer closer; ///< Comm close handler callback
};

/// Base class for FTP over HTTP and FTP Gateway server state.
class ServerStateData: public ::ServerStateData
{
public:
    ServerStateData(FwdState *fwdState);
    virtual ~ServerStateData();

    virtual void failed(err_type error = ERR_NONE, int xerrno = 0);
    virtual void timeout(const CommTimeoutCbParams &io);
    virtual const Comm::ConnectionPointer & dataConnection() const;
    virtual void abortTransaction(const char *reason);
    void writeCommand(const char *buf);

    /// extracts remoteAddr from PASV response, validates it,
