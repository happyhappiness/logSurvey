    AsyncCall::Pointer closer; ///< Comm close handler callback
};

/// Base class for FTP Gateway and FTP Native client classes.
class Client: public ::ServerStateData
{
public:
    explicit Client(FwdState *fwdState);
    virtual ~Client();

    /// handle a fatal transaction error, closing the control connection
    virtual void failed(err_type error = ERR_NONE, int xerrno = 0);

    /// read timeout handler
    virtual void timeout(const CommTimeoutCbParams &io);

    /* ServerStateData API */
    virtual void maybeReadVirginBody();

    void writeCommand(const char *buf);

    /// extracts remoteAddr from PASV response, validates it,
