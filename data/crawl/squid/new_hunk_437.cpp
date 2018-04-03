    /// stops monitoring server connection for closure and updates pconn stats
    void closeServerConnection(const char *reason);

    void syncWithServerConn(const char *host);

public:
    StoreEntry *entry;
    HttpRequest *request;
