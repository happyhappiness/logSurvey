extern int httpHeaderParseInt(const char *start, int *val);
extern int httpHeaderParseSize(const char *start, size_t * sz);
#ifdef __STDC__
extern void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...);
#else
extern void
     httpHeaderPutStrf();
#endif


/* Http Header */
extern void httpHeaderInitModule();
extern void httpHeaderCleanModule();
/* init/clean */
extern void httpHeaderInit(HttpHeader * hdr, http_hdr_owner_type owner);
extern void httpHeaderClean(HttpHeader * hdr);
/* append/update */
extern void httpHeaderAppend(HttpHeader * dest, const HttpHeader * src);
extern void httpHeaderUpdate(HttpHeader * old, const HttpHeader * fresh, const HttpHeaderMask * denied_mask);
/* parse/pack */
extern int httpHeaderParse(HttpHeader * hdr, const char *header_start, const char *header_end);
extern void httpHeaderPackInto(const HttpHeader * hdr, Packer * p);
/* field manipulation */
extern int httpHeaderHas(const HttpHeader * hdr, http_hdr_type type);
extern void httpHeaderPutInt(HttpHeader * hdr, http_hdr_type type, int number);
extern void httpHeaderPutTime(HttpHeader * hdr, http_hdr_type type, time_t time);
extern void httpHeaderPutStr(HttpHeader * hdr, http_hdr_type type, const char *str);
extern void httpHeaderPutAuth(HttpHeader * hdr, const char *authScheme, const char *realm);
extern void httpHeaderPutCc(HttpHeader * hdr, const HttpHdrCc * cc);
extern void httpHeaderPutContRange(HttpHeader * hdr, const HttpHdrContRange * cr);
extern void httpHeaderPutRange(HttpHeader * hdr, const HttpHdrRange * range);
extern void httpHeaderPutExt(HttpHeader * hdr, const char *name, const char *value);
extern int httpHeaderGetInt(const HttpHeader * hdr, http_hdr_type id);
extern time_t httpHeaderGetTime(const HttpHeader * hdr, http_hdr_type id);
extern HttpHdrCc *httpHeaderGetCc(const HttpHeader * hdr);
extern HttpHdrRange *httpHeaderGetRange(const HttpHeader * hdr);
extern HttpHdrContRange *httpHeaderGetContRange(const HttpHeader * hdr);
extern const char *httpHeaderGetStr(const HttpHeader * hdr, http_hdr_type id);
extern const char *httpHeaderGetLastStr(const HttpHeader * hdr, http_hdr_type id);
extern const char *httpHeaderGetAuth(const HttpHeader * hdr, http_hdr_type id, const char *authScheme);
extern String httpHeaderGetList(const HttpHeader * hdr, http_hdr_type id);
extern int httpHeaderDelByName(HttpHeader * hdr, const char *name);
extern int httpHeaderDelById(HttpHeader * hdr, http_hdr_type id);
extern void httpHeaderDelAt(HttpHeader * hdr, HttpHeaderPos pos);
/* avoid using these low level routines */
extern HttpHeaderEntry *httpHeaderGetEntry(const HttpHeader * hdr, HttpHeaderPos * pos);
extern HttpHeaderEntry *httpHeaderFindEntry(const HttpHeader * hdr, http_hdr_type id);
extern void httpHeaderAddEntry(HttpHeader * hdr, HttpHeaderEntry * e);
extern HttpHeaderEntry *httpHeaderEntryClone(const HttpHeaderEntry * e);
extern void httpHeaderEntryPackInto(const HttpHeaderEntry * e, Packer * p);
/* store report about current header usage and other stats */
extern void httpHeaderStoreReport(StoreEntry * e);

/* Http Msg (currently in HttpReply.c @?@ ) */
extern int httpMsgIsPersistent(float http_ver, const HttpHeader * hdr);
extern int httpMsgIsolateHeaders(const char **parse_start, const char **blk_start, const char **blk_end);

/* Http Reply */
extern void httpReplyInitModule();
/* create/destroy */
extern HttpReply *httpReplyCreate();
extern void httpReplyDestroy(HttpReply * rep);
/* reset: clean, then init */
extern void httpReplyReset(HttpReply * rep);
/* absorb: copy the contents of a new reply to the old one, destroy new one */
extern void httpReplyAbsorb(HttpReply * rep, HttpReply * new_rep);
/* parse returns -1,0,+1 on error,need-more-data,success */
extern int httpReplyParse(HttpReply * rep, const char *buf);	/*, int atEnd); */
extern void httpReplyPackInto(const HttpReply * rep, Packer * p);
/* ez-routines */
/* mem-pack: returns a ready to use mem buffer with a packed reply */
extern MemBuf httpReplyPack(const HttpReply * rep);
/* swap: create swap-based packer, pack, destroy packer */
extern void httpReplySwapOut(const HttpReply * rep, StoreEntry * e);
/* set commonly used info with one call */
extern void httpReplySetHeaders(HttpReply * rep, double ver, http_status status,
    const char *reason, const char *ctype, int clen, time_t lmt, time_t expires);
/* do everything in one call: init, set, pack, clean, return MemBuf */
extern MemBuf httpPackedReply(double ver, http_status status, const char *ctype,
    int clen, time_t lmt, time_t expires);
/* construct 304 reply and pack it into MemBuf, return MemBuf */
extern MemBuf httpPacked304Reply(const HttpReply * rep);
/* update when 304 reply is received for a cached object */
extern void httpReplyUpdateOnNotModified(HttpReply * rep, HttpReply * freshRep);
/* header manipulation */
extern int httpReplyContentLen(const HttpReply * rep);
extern const char *httpReplyContentType(const HttpReply * rep);
extern time_t httpReplyExpires(const HttpReply * rep);
extern int httpReplyHasCc(const HttpReply * rep, http_hdr_cc_type type);

/* Http Request */
extern request_t *requestCreate(method_t, protocol_t, const char *urlpath);
extern void requestDestroy(request_t *);
extern request_t *requestLink(request_t *);
extern void requestUnlink(request_t *);
extern int httpRequestParseHeader(request_t * req, const char *parse_start);
extern void httpRequestSwapOut(const request_t * req, StoreEntry * e);
extern int httpRequestPrefixLen(const request_t * req);
extern int httpRequestHdrAllowed(const HttpHeaderEntry * e, String * strConnection);

extern void icmpOpen(void);
extern void icmpClose(void);
extern void icmpPing(struct in_addr to);
extern void icmpSourcePing(struct in_addr to, const icp_common_t *, const char *url);
extern void icmpDomainPing(struct in_addr to, const char *domain);

extern void *icpCreateMessage(icp_opcode opcode,
    int flags,
    const char *url,
    int reqnum,
    int pad);
extern int icpUdpSend(int, const struct sockaddr_in *, icp_common_t *, log_type, int);
extern PF icpHandleUdp;
extern PF httpAccept;

#ifdef SQUID_SNMP
extern PF snmpHandleUdp;
extern void snmpInit(void);
extern int snmpInitConfig(void);
extern void snmpConnectionOpen(void);
extern void snmpConnectionShutdown(void);
extern void snmpConnectionClose(void);
extern int snmpCreateView(char **);
extern int snmpCreateUser(char **);
extern int snmpCreateCommunity(char **);
extern void snmpTokenize(char *, char **, int);
extern int snmpCompare(oid * name1, int len1, oid * name2, int len2);
#endif /* SQUID_SNMP */

extern void icpHandleIcpV3(int, struct sockaddr_in, char *, int);
extern int icpCheckUdpHit(StoreEntry *, request_t * request);
extern void icpConnectionsOpen(void);
extern void icpConnectionShutdown(void);
extern void icpConnectionClose(void);

extern void ipcache_nbgethostbyname(const char *name,
    IPH * handler,
    void *handlerData);
extern EVH ipcache_purgelru;
extern const ipcache_addrs *ipcache_gethostbyname(const char *, int flags);
extern void ipcacheInvalidate(const char *);
extern void ipcacheReleaseInvalid(const char *);
extern void ipcacheShutdownServers(void);
extern void ipcache_init(void);
extern void stat_ipcache_get(StoreEntry *);
extern int ipcacheQueueDrain(void);
extern void ipcacheCycleAddr(const char *name, ipcache_addrs *);
extern void ipcacheMarkBadAddr(const char *name, struct in_addr);
extern void ipcacheMarkGoodAddr(const char *name, struct in_addr);
extern void ipcacheFreeMemory(void);
extern ipcache_addrs *ipcacheCheckNumeric(const char *name);
extern void ipcache_restart(void);
extern int ipcacheUnregister(const char *name, void *data);

/* MemBuf */
/* init with specific sizes */
extern void memBufInit(MemBuf * mb, mb_size_t szInit, mb_size_t szMax);
/* init with defaults */
extern void memBufDefInit(MemBuf * mb);
/* cleans mb; last function to call if you do not give .buf away */
extern void memBufClean(MemBuf * mb);
/* resets mb preserving (or initializing if needed) memory buffer */
extern void memBufReset(MemBuf * mb);
/* calls memcpy, appends exactly size bytes, extends buffer if needed */
extern void memBufAppend(MemBuf * mb, const char *buf, mb_size_t size);
/* calls snprintf, extends buffer if needed */
#ifdef __STDC__
extern void memBufPrintf(MemBuf * mb, const char *fmt,...);
#else
extern void memBufPrintf();
#endif
/* vprintf for other printf()'s to use */
extern void memBufVPrintf(MemBuf * mb, const char *fmt, va_list ap);
/* returns free() function to be used, _freezes_ the object! */
extern FREE *memBufFreeFunc(MemBuf * mb);
/* puts report on MemBuf _module_ usage into mb */
extern void memBufReport(MemBuf * mb);

extern char *mime_get_header(const char *mime, const char *header);
extern char *mime_get_header_field(const char *mime, const char *name, const char *prefix);
#if OLD_CODE
extern char *mime_headers_end(const char *mime);
#endif
extern size_t headersEnd(const char *, size_t);
extern const char *mime_get_auth(const char *hdr, const char *auth_scheme, const char **auth_field);

extern void mimeInit(char *filename);
extern char *mimeGetContentEncoding(const char *fn);
extern char *mimeGetContentType(const char *fn);
extern char *mimeGetIcon(const char *fn);
extern char *mimeGetIconURL(const char *fn);
extern char mimeGetTransferMode(const char *fn);

extern int mcastSetTtl(int, int);
extern IPH mcastJoinGroups;

/* Labels for hierachical log file */
/* put them all here for easier reference when writing a logfile analyzer */


extern peer *getFirstPeer(void);
extern peer *getFirstUpParent(request_t *);
extern peer *getNextPeer(peer *);
extern peer *getSingleParent(request_t *);
extern int neighborsCount(request_t *);
extern int neighborsUdpPing(request_t *,
    StoreEntry *,
    IRCB * callback,
    void *data,
    int *exprep,
    double *exprtt);
extern void neighborAddAcl(const char *, const char *);
extern void neighborsUdpAck(const cache_key *, icp_common_t *, const struct sockaddr_in *);
extern void neighborAdd(const char *, const char *, int, int, int, int, int);
extern void neighbors_open(int);
extern peer *peerFindByName(const char *);
extern peer *getDefaultParent(request_t * request);
extern peer *getRoundRobinParent(request_t * request);
extern lookup_t peerDigestLookup(peer * p, request_t * request, StoreEntry * entry);
extern peer *neighborsDigestSelect(request_t * request, StoreEntry * entry);
extern void peerNoteDigestLookup(request_t * request, peer * p, lookup_t lookup);
extern int neighborUp(const peer * e);
extern void peerDestroy(peer * e);
extern char *neighborTypeStr(const peer * e);
extern void peerCheckConnectStart(peer *);
extern void dump_peer_options(StoreEntry *, peer *);
extern int peerHTTPOkay(const peer *, request_t *);

extern void netdbInit(void);
extern void netdbHandlePingReply(const struct sockaddr_in *from, int hops, int rtt);
extern void netdbPingSite(const char *hostname);
extern void netdbInit(void);
extern void netdbDump(StoreEntry *);
extern int netdbHops(struct in_addr);
extern void netdbFreeMemory(void);
extern int netdbHostHops(const char *host);
extern int netdbHostRtt(const char *host);
extern int netdbHostPeerRtt(const char *host, peer * peer);
extern void netdbUpdatePeer(request_t *, peer * e, int rtt, int hops);
extern void netdbDeleteAddrNetwork(struct in_addr addr);
extern int netdbHostPeerRtt(const char *host, peer * peer);
extern void netdbBinaryExchange(StoreEntry *);
extern EVH netdbExchangeStart;
extern void netdbExchangeUpdatePeer(struct in_addr, peer *, double, double);
extern peer *netdbClosestParent(request_t *);

extern void cachemgrStart(int fd, request_t * request, StoreEntry * entry);
extern void cachemgrRegister(const char *, const char *, OBJH *, int);
extern void cachemgrInit(void);

extern void peerSelect(request_t *, StoreEntry *, PSC *, PSC *, void *data);
extern peer *peerGetSomeParent(request_t *, hier_code *);
extern void peerSelectInit(void);

/* peer_digest.c */
extern EVH peerDigestInit;

extern void protoDispatch(int, StoreEntry *, request_t *);

extern int protoUnregister(StoreEntry *, request_t *);
extern int protoAbortFetch(StoreEntry * entry);
extern DEFER protoCheckDeferRead;

extern void urnStart(request_t *, StoreEntry *);

extern void redirectStart(clientHttpRequest *, RH *, void *);
extern void redirectOpenServers(void);
extern void redirectShutdownServers(void);
extern void redirectStats(StoreEntry *);
extern int redirectUnregister(const char *url, void *);
extern void redirectFreeMemory(void);

extern void refreshAddToList(const char *, int, time_t, int, time_t);
extern int refreshCheck(const StoreEntry *, const request_t *, time_t delta);
extern time_t refreshWhen(const StoreEntry * entry);
extern time_t getMaxAge(const char *url);

extern void serverConnectionsClose(void);
extern void shut_down(int);


extern void start_announce(void *unused);
extern void sslStart(int fd, const char *, request_t *, size_t * sz);
extern void waisStart(request_t *, StoreEntry *);
extern void passStart(int, const char *, request_t *, size_t *);
extern void identStart(int, ConnStateData *, IDCB * callback, void *);

extern void statInit(void);
extern double median_svc_get(int, int);
extern void pconnHistCount(int, int);
extern int stat5minClientRequests(void);


/* StatHist */
extern void statHistClean(StatHist * H);
extern void statHistCount(StatHist * H, double val);
extern void statHistCopy(StatHist * Dest, const StatHist * Orig);
extern void statHistSafeCopy(StatHist * Dest, const StatHist * Orig);
extern double statHistDeltaMedian(const StatHist * A, const StatHist * B);
extern void statHistDump(const StatHist * H, StoreEntry * sentry, StatHistBinDumper bd);
extern void statHistLogInit(StatHist * H, int capacity, double min, double max);
extern void statHistEnumInit(StatHist * H, int last_enum);
extern StatHistBinDumper statHistEnumDumper;
extern StatHistBinDumper statHistIntDumper;


/* MemMeter */
extern void memMeterSyncHWater(MemMeter * m);
#define memMeterCheckHWater(m) { if ((m).hwater_level < (m).level) memMeterSyncHWater(&(m)); }
#define memMeterInc(m) { (m).level++; memMeterCheckHWater(m); }
#define memMeterDec(m) { (m).level--; }
#define memMeterAdd(m, sz) { (m).level += (sz); memMeterCheckHWater(m); }
#define memMeterDel(m, sz) { (m).level -= (sz); }

/* mem */
extern void memInit(void);
extern void memClean();
extern void memInitModule();
extern void memCleanModule();
extern void memConfigure();
extern void *memAllocate(mem_type);
extern void *memAllocBuf(size_t net_size, size_t * gross_size);
extern void memFree(mem_type, void *);
extern void memFreeBuf(size_t size, void *);
extern void memFree2K(void *);
extern void memFree4K(void *);
extern void memFree8K(void *);
extern void memFreeDISK(void *);
extern int memInUse(mem_type);
extern size_t memTotalAllocated();

/* MemPool */
extern MemPool *memPoolCreate(const char *label, size_t obj_size);
extern void memPoolDestroy(MemPool * pool);
extern void *memPoolAlloc(MemPool * pool);
extern void memPoolFree(MemPool * pool, void *obj);
extern int memPoolWasUsed(const MemPool * pool);
extern int memPoolInUseCount(const MemPool * pool);
extern size_t memPoolInUseSize(const MemPool * pool);
extern int memPoolUsedCount(const MemPool * pool);
extern void memPoolReport(const MemPool * pool, StoreEntry * e);

/* Mem */
extern void memReport(StoreEntry * e);
extern size_t memTotalAllocated(void);

extern int stmemFreeDataUpto(mem_hdr *, int);
extern void stmemAppend(mem_hdr *, const char *, int);
extern ssize_t stmemCopy(const mem_hdr *, off_t, char *, size_t);
extern void stmemFree(mem_hdr *);
extern void stmemFreeData(mem_hdr *);

/* ----------------------------------------------------------------- */

/*
 * store.c
 */
extern StoreEntry *new_StoreEntry(int, const char *, const char *);
extern StoreEntry *storeGet(const cache_key *);
extern StoreEntry *storeCreateEntry(const char *, const char *, int, method_t);
extern void storeSetPublicKey(StoreEntry *);
extern void storeComplete(StoreEntry *);
extern void storeInit(void);
extern int storeClientWaiting(const StoreEntry *);
extern void storeAbort(StoreEntry *, int);
extern void storeAppend(StoreEntry *, const char *, int);
extern void storeLockObject(StoreEntry *);
extern void storeSwapInStart(StoreEntry *, SIH *, void *data);
extern void storeRelease(StoreEntry *);
extern int storeUnlockObject(StoreEntry *);
extern int storeUnregister(StoreEntry *, void *);
extern void storeClientCopy(StoreEntry * e,
    off_t seen_offset,
    off_t copy_offset,
    size_t size,
    char *buf,
    STCB * callback,
    void *data);
extern int storePendingNClients(const StoreEntry *);
extern HASHCMP urlcmp;
extern EVH storeMaintainSwapSpace;
extern void storeExpireNow(StoreEntry *);
extern void storeReleaseRequest(StoreEntry *);
extern off_t storeLowestMemReaderOffset(const StoreEntry *);
extern void storeConfigure(void);
extern void storeNegativeCache(StoreEntry *);
extern void storeFreeMemory(void);
extern int expiresMoreThan(time_t, time_t);
extern int storeClientCopyPending(StoreEntry *, void *);
extern void InvokeHandlers(StoreEntry *);
extern int storeEntryValidToSend(StoreEntry *);
extern void storeTimestampsSet(StoreEntry *);
extern time_t storeExpiredReferenceAge(void);
extern void storeRegisterAbort(StoreEntry * e, STABH * cb, void *);
extern void storeUnregisterAbort(StoreEntry * e);
extern void storeMemObjectDump(MemObject * mem);
extern void storeEntryDump(StoreEntry * e, int debug_lvl);
extern const char *storeUrl(const StoreEntry *);
extern void storeCreateMemObject(StoreEntry *, const char *, const char *);
extern void storeCopyNotModifiedReplyHeaders(MemObject * O, MemObject * N);
extern void storeBuffer(StoreEntry *);
extern void storeBufferFlush(StoreEntry *);
extern void storeHashInsert(StoreEntry * e, const cache_key *);
extern void storeSetMemStatus(StoreEntry * e, int);
#ifdef __STDC__
extern void storeAppendPrintf(StoreEntry *, const char *,...);
#else
extern void storeAppendPrintf();
#endif
extern void storeAppendVPrintf(StoreEntry *, const char *, va_list ap);
extern int storeCheckCachable(StoreEntry * e);
extern void storeUnlinkFileno(int fileno);
extern void storeSetPrivateKey(StoreEntry *);
extern int objectLen(const StoreEntry * e);
extern int contentLen(const StoreEntry * e);
extern HttpReply *storeEntryReply(StoreEntry *);

/*
 * store_log.c
 */
extern void storeLog(int tag, const StoreEntry * e);
extern void storeLogRotate(void);
extern void storeLogClose(void);
extern void storeLogOpen(void);


/*
 * store_key_*.c
 */
extern const cache_key *storeKeyDup(const cache_key *);
extern void storeKeyFree(const cache_key *);
extern const cache_key *storeKeyScan(const char *);
extern const char *storeKeyText(const cache_key *);
extern const cache_key *storeKeyPublic(const char *, method_t);
extern const cache_key *storeKeyPrivate(const char *, method_t, int);
extern int storeKeyHashBuckets(int);
extern int storeKeyNull(const cache_key *);
extern void storeKeyInit(void);
extern HASHHASH storeKeyHashHash;
extern HASHCMP storeKeyHashCmp;

/*
 * store_clean.c
 */
extern EVH storeDirClean;

/* store_digest.c */
extern void storeDigestInit();
extern void storeDigestNoteStoreReady();
extern void storeDigestScheduleRebuild();
extern void storeDigestAdd(const StoreEntry * entry);
extern void storeDigestDel(const StoreEntry * entry);
extern void storeDigestReport();

/*
 * store_dir.c
 */
extern char *storeSwapFullPath(int, char *);
extern char *storeSwapSubSubDir(int, char *);
extern int storeVerifySwapDirs(void);
extern const char *storeSwapPath(int);
extern int storeDirMapBitTest(int fn);
extern void storeDirMapBitSet(int fn);
extern void storeDirMapBitReset(int fn);
extern int storeDirMapAllocate(void);
extern char *storeSwapDir(int);
extern FILE *storeDirOpenTmpSwapLog(int dirn, int *clean, int *zero);
extern void storeDirCloseTmpSwapLog(int dirn);
extern void storeDirOpenSwapLogs(void);
extern void storeDirCloseSwapLogs(void);
extern char *storeDirSwapLogFile(int, const char *);
extern void storeDirSwapLog(const StoreEntry *, int op);
extern int storeDirNumber(int fileno);
extern void storeDirUpdateSwapSize(int fn, size_t size, int sign);
extern int storeDirProperFileno(int dirn, int fn);
extern void storeCreateSwapDirectories(void);
extern int storeVerifyCacheDirs(void);
extern int storeDirWriteCleanLogs(int reopen);
extern int storeDirValidFileno(int fn);
extern int storeFilenoBelongsHere(int, int, int, int);
extern OBJH storeDirStats;
extern int storeDirMapBitsInUse(void);


/*
 * store_swapmeta.c
 */
extern char *storeSwapMetaPack(tlv * tlv_list, int *length);
extern tlv *storeSwapMetaBuild(StoreEntry * e);
extern tlv *storeSwapMetaUnpack(const char *buf, int *hdrlen);
extern void storeSwapTLVFree(tlv * n);

/*
 * store_rebuild.c
 */
extern void storeDoRebuildFromSwapFiles(void *data);
extern void storeValidate(StoreEntry *, STVLDCB *, void *, void *);
extern void storeValidateComplete(void *data, int retcode, int errcode);
extern void storeRebuildStart(void);

/*
 * store_swapin.c
 */
extern void storeSwapInStart(StoreEntry * e, SIH * callback, void *callback_data);
extern void storeSwapInValidateComplete(void *data, int retcode, int errcode);
extern void storeSwapInFileOpened(void *data, int fd, int errcode);

/*
 * store_swapout.c
 */
extern void storeSwapOutStart(StoreEntry * e);
extern void storeSwapOutHandle(int fdnotused, int flag, size_t len, void *data);
extern void storeCheckSwapOut(StoreEntry * e);
extern void storeSwapOutFileClose(StoreEntry * e);
extern int storeSwapOutWriteQueued(MemObject * mem);

/*
 * store_client.c
 */
extern store_client *storeClientListSearch(const MemObject * mem, void *data);
extern void storeClientListAdd(StoreEntry * e, void *data);
extern void storeClientCopy(StoreEntry *, off_t, off_t, size_t, char *, STCB *, void *);
extern int storeClientCopyPending(StoreEntry * e, void *data);
extern int storeUnregister(StoreEntry * e, void *data);
extern off_t storeLowestMemReaderOffset(const StoreEntry * entry);
extern void InvokeHandlers(StoreEntry * e);
extern int storePendingNClients(const StoreEntry * e);


extern const char *getMyHostname(void);
extern void safeunlink(const char *path, int quiet);
extern void death(int sig);
extern void fatal(const char *message);
#ifdef __STDC__
extern void fatalf(const char *fmt,...);
#else
extern void fatalf();
#endif
extern void fatal_dump(const char *message);
extern void sigusr2_handle(int sig);
extern void sig_child(int sig);
extern void leave_suid(void);
extern void enter_suid(void);
extern void no_suid(void);
extern void writePidFile(void);
extern void setSocketShutdownLifetimes(int);
extern void setMaxFD(void);
extern time_t getCurrentTime(void);
extern int percent(int, int);
extern double dpercent(double, double);
extern void squid_signal(int sig, SIGHDLR *, int flags);
extern pid_t readPidFile(void);
extern struct in_addr inaddrFromHostent(const struct hostent *hp);
extern int intAverage(int, int, int, int);
extern double doubleAverage(double, double, int, int);
extern void debug_trap(const char *);
extern void logsFlush(void);
extern char *checkNullString(char *p);
extern void squid_getrusage(struct rusage *r);
extern double rusage_cputime(struct rusage *r);
extern int rusage_maxrss(struct rusage *r);
extern int rusage_pagefaults(struct rusage *r);
extern void releaseServerSockets(void);
extern void PrintRusage(void);
extern void dumpMallocStats(void);

extern void pumpInit(int fd, request_t * r, char *uri);
extern void pumpStart(int, StoreEntry *, request_t *, CWCB * callback, void *);
extern int pumpMethod(method_t method);
extern int pumpRestart(request_t *);

extern void unlinkdInit(void);
extern void unlinkdClose(void);
extern void unlinkdUnlink(const char *);

extern char *url_convert_hex(char *org_url, int allocate);
extern char *url_escape(const char *url);
extern protocol_t urlParseProtocol(const char *);
extern method_t urlParseMethod(const char *);
extern void urlInitialize(void);
extern request_t *urlParse(method_t, char *);
extern char *urlCanonical(const request_t *, char *);
extern char *urlRInternal(const char *host, u_short port, const char *dir, const char *name);
extern char *urlInternal(const char *dir, const char *name);
extern int matchDomainName(const char *d, const char *h);
extern int urlCheckRequest(const request_t *);
extern int urlDefaultPort(protocol_t p);
extern char *urlCanonicalClean(const request_t *);
extern char *urlHostname(const char *url);

extern void useragentOpenLog(void);
extern void useragentRotateLog(void);
extern void logUserAgent(const char *, const char *);
extern peer_t parseNeighborType(const char *s);

extern HttpReply *errorBuildReply(ErrorState * err);
extern void errorSend(int fd, ErrorState *);
extern void errorAppendEntry(StoreEntry *, ErrorState *);
extern void errorStateFree(ErrorState * err);
extern void errorInitialize(void);
extern int errorReservePageId(const char *page_name);
extern void errorFree(void);
extern ErrorState *errorCon(int type, http_status);

extern void pconnPush(int, const char *host, u_short port);
extern int pconnPop(const char *host, u_short port);
extern void pconnInit(void);

extern int asnMatchIp(void *, struct in_addr);
extern void asnInit(void);
extern void asnFreeMemory(void);
extern void dlinkAdd(void *data, dlink_node *, dlink_list *);
extern void dlinkDelete(dlink_node * m, dlink_list * list);
extern void kb_incr(kb_t *, size_t);
extern double gb_to_double(const gb_t *);
extern const char *gb_to_str(const gb_t *);
extern void gb_flush(gb_t *);	/* internal, do not use this */

#if USE_HTCP
extern void htcpInit(void);
extern void htcpQuery(StoreEntry * e, request_t * req, peer * p);
extern void htcpSocketShutdown(void);
extern void htcpSocketClose(void);
#endif

/* String */