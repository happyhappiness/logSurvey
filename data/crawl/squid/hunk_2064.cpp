 #include "enums.h"
 /* some parameters stil need this */
 #include "wordlist.h"
-
-/* for parameters that still need these */
+#include "anyp/ProtocolType.h"
+#include "Debug.h"
+#include "HttpHeader.h"
+#include "HttpStatusCode.h"
 #include "lookup_t.h"
 
+
 class HttpRequestMethod;
 #if USE_DELAY_POOLS
 class ClientInfo;
 #endif
 
-#if USE_FORW_VIA_DB
-extern void fvdbCountVia(const char *key);
-extern void fvdbCountForw(const char *key);
-#endif
-#if HEADERS_LOG
-SQUIDCEXTERN void headersLog(int cs, int pq, const HttpRequestMethod& m, void *data);
-#endif
-extern int logTypeIsATcpHit(log_type);
-
-/*
- * cache_cf.c
- */
-SQUIDCEXTERN void configFreeMemory(void);
-class MemBuf;
-extern void wordlistCat(const wordlist *, MemBuf * mb);
-extern void self_destruct(void);
-SQUIDCEXTERN void add_http_port(char *portspec);
-extern int xatoi(const char *token);
-extern long xatol(const char *token);
-
-/* extra functions from cache_cf.c useful for lib modules */
-SQUIDCEXTERN void parse_int(int *var);
-SQUIDCEXTERN void parse_onoff(int *var);
-SQUIDCEXTERN void parse_eol(char *volatile *var);
-SQUIDCEXTERN void parse_wordlist(wordlist ** list);
-SQUIDCEXTERN void requirePathnameExists(const char *name, const char *path);
-SQUIDCEXTERN void parse_time_t(time_t * var);
-
-/* client_side.c - FD related client side routines */
-
-SQUIDCEXTERN void clientdbInit(void);
-
-#include "anyp/ProtocolType.h"
-SQUIDCEXTERN void clientdbUpdate(const Ip::Address &, log_type, AnyP::ProtocolType, size_t);
-
-SQUIDCEXTERN int clientdbCutoffDenied(const Ip::Address &);
-void clientdbDump(StoreEntry *);
-SQUIDCEXTERN void clientdbFreeMemory(void);
-
-SQUIDCEXTERN int clientdbEstablished(const Ip::Address &, int);
-#if USE_DELAY_POOLS
-SQUIDCEXTERN void clientdbSetWriteLimiter(ClientInfo * info, const int writeSpeedLimit,const double initialBurst,const double highWatermark);
-SQUIDCEXTERN ClientInfo * clientdbGetInfo(const Ip::Address &addr);
-#endif
-SQUIDCEXTERN void clientOpenListenSockets(void);
-SQUIDCEXTERN void clientHttpConnectionsClose(void);
-SQUIDCEXTERN void httpRequestFree(void *);
-
-extern void clientAccessCheck(void *);
-
-#include "Debug.h"
-
-/* packs, then prints an object using debugs() */
-SQUIDCEXTERN void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm);
-
-/* disk.c */
-SQUIDCEXTERN int file_open(const char *path, int mode);
-SQUIDCEXTERN void file_close(int fd);
-/* Adapter file_write for object callbacks */
-
-template <class O>
-void
-FreeObject(void *address)
-{
-    O *anObject = static_cast <O *>(address);
-    delete anObject;
-}
-
-SQUIDCEXTERN void file_write(int, off_t, void const *, int len, DWCB *, void *, FREE *);
-SQUIDCEXTERN void file_write_mbuf(int fd, off_t, MemBuf mb, DWCB * handler, void *handler_data);
-SQUIDCEXTERN void file_read(int, char *, int, off_t, DRCB *, void *);
-SQUIDCEXTERN void disk_init(void);
-
-extern void fd_close(int fd);
-extern void fd_open(int fd, unsigned int type, const char *);
-extern void fd_note(int fd, const char *);
-extern void fd_bytes(int fd, int len, unsigned int type);
-extern void fdDumpOpen(void);
-extern int fdUsageHigh(void);
-extern void fdAdjustReserved(void);
-
-SQUIDCEXTERN void fqdncache_nbgethostbyaddr(const Ip::Address &, FQDNH *, void *);
-
-SQUIDCEXTERN const char *fqdncache_gethostbyaddr(const Ip::Address &, int flags);
-SQUIDCEXTERN void fqdncache_init(void);
-void fqdnStats(StoreEntry *);
-SQUIDCEXTERN void fqdncacheReleaseInvalid(const char *);
-
-SQUIDCEXTERN const char *fqdnFromAddr(const Ip::Address &);
-SQUIDCEXTERN int fqdncacheQueueDrain(void);
-SQUIDCEXTERN void fqdncacheFreeMemory(void);
-SQUIDCEXTERN void fqdncache_restart(void);
-extern void fqdncache_purgelru(void *);
-SQUIDCEXTERN void fqdncacheAddEntryFromHosts(char *addr, wordlist * hostnames);
 
 class FwdState;
 
-/**
- \defgroup ServerProtocolFTPAPI Server-Side FTP API
- \ingroup ServerProtocol
- */
-
-/// \ingroup ServerProtocolFTPAPI
-SQUIDCEXTERN void ftpStart(FwdState *);
 
 class HttpRequest;
 class HttpReply;
 
-/// \ingroup ServerProtocolFTPAPI
-SQUIDCEXTERN const char *ftpUrlWith2f(HttpRequest *);
-
-/**
- \defgroup ServerProtocolGopherAPI Server-Side Gopher API
- \ingroup ServerProtocol
- */
-
-/// \ingroup ServerProtocolGopherAPI
-SQUIDCEXTERN void gopherStart(FwdState *);
-
-/// \ingroup ServerProtocolGopherAPI
-SQUIDCEXTERN int gopherCachable(const HttpRequest *);
-
-/**
- \defgroup ServerProtocolWhoisAPI Server-Side WHOIS API
- \ingroup ServerProtocol
- */
-
-/// \ingroup ServerProtocolWhoisAPI
-SQUIDCEXTERN void whoisStart(FwdState *);
-
-/* http.c */
-/* for http_hdr_type field */
-#include "HttpHeader.h"
-SQUIDCEXTERN int httpCachable(const HttpRequestMethod&);
-SQUIDCEXTERN void httpStart(FwdState *);
-SQUIDCEXTERN mb_size_t httpBuildRequestPrefix(HttpRequest * request,
-        HttpRequest * orig_request,
-        StoreEntry * entry,
-        MemBuf * mb,
-        http_state_flags);
-extern const char *httpMakeVaryMark(HttpRequest * request, HttpReply const * reply);
-
-#include "HttpStatusCode.h"
-
-class StatHist;
-
-/* Http Cache Control Header Field */
-SQUIDCEXTERN void httpHdrCcInitModule(void);
-SQUIDCEXTERN void httpHdrCcCleanModule(void);
-SQUIDCEXTERN void httpHdrCcUpdateStats(const HttpHdrCc * cc, StatHist * hist);
-extern void httpHdrCcStatDumper(StoreEntry * sentry, int idx, double val, double size, int count);
-
-/* Http Header Tools */
-class HttpHeaderFieldInfo;
-SQUIDCEXTERN HttpHeaderFieldInfo *httpHeaderBuildFieldsInfo(const HttpHeaderFieldAttrs * attrs, int count);
-SQUIDCEXTERN void httpHeaderDestroyFieldsInfo(HttpHeaderFieldInfo * info, int count);
-SQUIDCEXTERN http_hdr_type httpHeaderIdByName(const char *name, size_t name_len, const HttpHeaderFieldInfo * attrs, int end);
-SQUIDCEXTERN http_hdr_type httpHeaderIdByNameDef(const char *name, int name_len);
-SQUIDCEXTERN const char *httpHeaderNameById(int id);
-SQUIDCEXTERN int httpHeaderHasConnDir(const HttpHeader * hdr, const char *directive);
+/* TODO: move to StrList.h */
 SQUIDCEXTERN void strListAdd(String * str, const char *item, char del);
 SQUIDCEXTERN int strListIsMember(const String * str, const char *item, char del);
 SQUIDCEXTERN int strListIsSubstr(const String * list, const char *s, char del);
 SQUIDCEXTERN int strListGetItem(const String * str, char del, const char **item, int *ilen, const char **pos);
-SQUIDCEXTERN const char *getStringPrefix(const char *str, const char *end);
-SQUIDCEXTERN int httpHeaderParseInt(const char *start, int *val);
-SQUIDCEXTERN void httpHeaderPutStrf(HttpHeader * hdr, http_hdr_type id, const char *fmt,...) PRINTF_FORMAT_ARG3;
 
-/* Http Header */
-SQUIDCEXTERN void httpHeaderInitModule(void);
-SQUIDCEXTERN void httpHeaderCleanModule(void);
+extern const char *getStringPrefix(const char *str, const char *end);
+
+
 
 /* store report about current header usage and other stats */
 void httpHeaderStoreReport(StoreEntry * e);
