
CBDATA_CLASS_INIT(RebuildState);

/// Parse a swap header entry created on a system with 32-bit size_t and sfileno
/// this is typical of 32-bit systems without large file support
/// NP: SQUID_MD5_DIGEST_LENGTH is very risky still.
class UFSSwapLogParser_v1_32bs:public UFSSwapLogParser
{
public:
    /// version 1 cache swap.state entry with 32-bit size_t (swap_file_sz)
    /// time_t an sfileno have no variation from the v1 baseline format
    struct StoreSwapLogDataOld {
        char op;
        sfileno swap_filen;
        time_t timestamp;
        time_t lastref;
        time_t expires;
        time_t lastmod;
        uint32_t swap_file_sz;
        u_short refcount;
        u_short flags;
        unsigned char key[SQUID_MD5_DIGEST_LENGTH];
    };
    UFSSwapLogParser_v1_32bs(FILE *fp):UFSSwapLogParser(fp) {
        record_size = sizeof(UFSSwapLogParser_v1_32bs::StoreSwapLogDataOld);
    }
    /// Convert the on-disk 32-bit format to our current format while reading
    bool ReadRecord(StoreSwapLogData &swapData) {
        UFSSwapLogParser_v1_32bs::StoreSwapLogDataOld readData;
        int bytes = sizeof(UFSSwapLogParser_v1_32bs::StoreSwapLogDataOld);

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
};

/// Parse a swap header entry created on a system with 32-bit size_t, time_t and sfileno
/// this is typical of 32-bit systems without large file support and with old kernels
/// NP: SQUID_MD5_DIGEST_LENGTH is very risky still.
class UFSSwapLogParser_v1_32bst:public UFSSwapLogParser
{
public:
    /// version 1 cache swap.state entry with 32-bit size_t (swap_file_sz)
    /// time_t also differs
    /// sfileno has no variation from the v1 baseline format
    struct StoreSwapLogDataOld {
        char op;
        sfileno swap_filen;
        int32_t timestamp;
        int32_t lastref;
        int32_t expires;
        int32_t lastmod;
        uint32_t swap_file_sz;
        u_short refcount;
        u_short flags;
        unsigned char key[SQUID_MD5_DIGEST_LENGTH];
    };
    UFSSwapLogParser_v1_32bst(FILE *fp):UFSSwapLogParser(fp) {
        record_size = sizeof(UFSSwapLogParser_v1_32bst::StoreSwapLogDataOld);
    }
    /// Convert the on-disk 32-bit format to our current format while reading
    bool ReadRecord(StoreSwapLogData &swapData) {
        UFSSwapLogParser_v1_32bst::StoreSwapLogDataOld readData;
        int bytes = sizeof(UFSSwapLogParser_v1_32bst::StoreSwapLogDataOld);

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
};

/// Parse a swap header entry created on a system with 64-bit size_t and sfileno
/// this is typical of 64-bit systems prior to this patch fixing sfileno to 32-bits
/// NP: SQUID_MD5_DIGEST_LENGTH is very risky still.
class UFSSwapLogParser_v1_64bfn:public UFSSwapLogParser
{
public:
    /// version 1 cache swap.state entry with 64-bit sfileno
    struct StoreSwapLogDataOld {
        char op;
        int64_t swap_filen;
        time_t timestamp;
        time_t lastref;
        time_t expires;
        time_t lastmod;
        uint64_t swap_file_sz;
        u_short refcount;
        u_short flags;
        unsigned char key[SQUID_MD5_DIGEST_LENGTH];
    };
    UFSSwapLogParser_v1_64bfn(FILE *fp):UFSSwapLogParser(fp) {
        record_size = sizeof(UFSSwapLogParser_v1_64bfn::StoreSwapLogDataOld);
    }
    /// Convert the on-disk 64-bit format to our current format while reading
    bool ReadRecord(StoreSwapLogData &swapData) {
        UFSSwapLogParser_v1_64bfn::StoreSwapLogDataOld readData;
        int bytes = sizeof(UFSSwapLogParser_v1_64bfn::StoreSwapLogDataOld);

        assert(log);

        if (fread(&readData, bytes, 1, log) != 1) {
            return false;
        }
        swapData.op = readData.op;
        if ((readData.swap_filen>>32) != 0) {
            fatalf("File ID on record is greater than maximum cache file ID.");
        }
        swapData.swap_filen = (int32_t)readData.swap_filen;
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
};

class UFSSwapLogParser_v1:public UFSSwapLogParser
{
