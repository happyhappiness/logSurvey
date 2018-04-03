private:
    void checkpoint();
    void steps();
    void doOneEntry();
    void failure(const char *msg, int errNo = 0);

    SwapDir *sd;

    int64_t dbSize;
    int dbEntrySize;
    int dbEntryLimit;

    int fd; // store db file descriptor
    int64_t dbOffset;
    int filen;

    StoreRebuildData counts;

