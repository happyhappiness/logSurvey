    void completed();
    void retryOrBail();
    ErrorState *makeConnectingError(const err_type type) const;
    static void RegisterWithCacheManager(void);

public:
    StoreEntry *entry;
    HttpRequest *request;
