
public:
    /** The root store */
    static _SQUID_INLINE_ Store &Root();
    static void Root(Store *);
    static void Root(RefCount<Store>);
    static void Stats(StoreEntry * output);