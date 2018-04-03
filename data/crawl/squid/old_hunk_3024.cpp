
CBDATA_CLASS_INIT(RebuildState);


class UFSSwapLogParser_old:public UFSSwapLogParser
{
public:
    struct StoreSwapLogDataOld {
        char op;
        sfileno swap_filen;
        time_t timestamp;
        time_t lastref;
        time_t expires;
        time_t lastmod;
        size_t swap_file_sz;
        u_short refcount;
        u_short flags;
        unsigned char key[SQUID_MD5_DIGEST_LENGTH];
    };
    UFSSwapLogParser_old(FILE *fp):UFSSwapLogParser(fp) {
        record_size = sizeof(UFSSwapLogParser_old::StoreSwapLogDataOld);
    }
    bool ReadRecord(StoreSwapLogData &swapData);
};


bool UFSSwapLogParser_old::ReadRecord(StoreSwapLogData &swapData)
{
    UFSSwapLogParser_old::StoreSwapLogDataOld readData;
    int bytes = sizeof(UFSSwapLogParser_old::StoreSwapLogDataOld);

    assert(log);

    if (fread(&readData, bytes, 1, log) != 1) {
        return false;
    }
    swapData.op = readData.op;
    swapData.swap_filen = readData.swap_filen;
    swapData.timestamp = readData.timestamp;
    swapData.lastref = readData.lastref;
    swapData.expires = readData.expires;
    swapData.lastmod = readData.lastmod;
    swapData.swap_file_sz = readData.swap_file_sz;
    swapData.refcount = readData.refcount;
    swapData.flags = readData.flags;
    xmemcpy(swapData.key, readData.key, SQUID_MD5_DIGEST_LENGTH);
    return true;
}


class UFSSwapLogParser_v1:public UFSSwapLogParser
{
