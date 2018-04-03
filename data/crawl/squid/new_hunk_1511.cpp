#endif
    static void RegisterWithCacheManager(void);

    /// stops monitoring server connection for closure and updates pconn stats
    void closeServerConnection(const char *reason);

public:
    StoreEntry *entry;
    HttpRequest *request;
