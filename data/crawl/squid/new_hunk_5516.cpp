
/*
 * $Id: Store.h,v 1.1 2002/10/13 20:34:57 robertc Exp $
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sources; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#ifndef SQUID_STORE_H
#define SQUID_STORE_H

#ifdef __cplusplus
class StoreClient;
#endif

struct _StoreEntry {
#ifdef __cplusplus
    public:
#endif
    hash_link hash;		/* must be first */
    MemObject *mem_obj;
    RemovalPolicyNode repl;
    /* START OF ON-DISK STORE_META_STD TLV field */
    time_t timestamp;
    time_t lastref;
    time_t expires;
    time_t lastmod;
    size_t swap_file_sz;
    u_short refcount;
    u_short flags;
    /* END OF ON-DISK STORE_META_STD */
    sfileno swap_filen:25;
    sdirno swap_dirn:7;
    u_short lock_count;		/* Assume < 65536! */
    mem_status_t mem_status:3;
    ping_status_t ping_status:3;
    store_status_t store_status:3;
    swap_status_t swap_status:3;
#ifdef __cplusplus
public:
    static size_t inUseCount();
    static void getPublicByRequestMethod(StoreClient * aClient, request_t * request, const method_t method);
    static void getPublicByRequest(StoreClient * aClient, request_t * request);
    static void getPublic(StoreClient * aClient, const char *uri, const method_t method);
    virtual bool isNull() {
	return false;
    }
    void *operator new(unsigned int byteCount);
    void operator delete(void *address);
private:
    static MemPool *pool;
#endif
};

#ifdef __cplusplus
class NullStoreEntry:public _StoreEntry
{
public:
    static NullStoreEntry *getInstance();
    bool isNull() {
	return true;
    }
    void operator delete(void *address);
         private:
    static NullStoreEntry _instance;
};

#endif

SQUIDCEXTERN size_t storeEntryInUse();
SQUIDCEXTERN const char *storeEntryFlags(const StoreEntry *);
SQUIDCEXTERN int storeEntryLocked(const StoreEntry *);

SQUIDCEXTERN StoreEntry *new_StoreEntry(int, const char *, const char *);
SQUIDCEXTERN StoreEntry *storeGet(const cache_key *);
SQUIDCEXTERN StoreEntry *storeGetPublic(const char *uri, const method_t method);
SQUIDCEXTERN StoreEntry *storeGetPublicByRequest(request_t * request);
SQUIDCEXTERN StoreEntry *storeGetPublicByRequestMethod(request_t * request, const method_t method);
SQUIDCEXTERN StoreEntry *storeCreateEntry(const char *, const char *, request_flags, method_t);
SQUIDCEXTERN void storeSetPublicKey(StoreEntry *);
SQUIDCEXTERN void storeComplete(StoreEntry *);
SQUIDCEXTERN void storeInit(void);
SQUIDCEXTERN void storeAbort(StoreEntry *);
SQUIDCEXTERN void storeAppend(StoreEntry *, const char *, int);
SQUIDCEXTERN void storeLockObject(StoreEntry *);
SQUIDCEXTERN void storeRelease(StoreEntry *);
SQUIDCEXTERN int storeUnlockObject(StoreEntry *);
SQUIDCEXTERN EVH storeMaintainSwapSpace;
SQUIDCEXTERN void storeExpireNow(StoreEntry *);
SQUIDCEXTERN void storeReleaseRequest(StoreEntry *);
SQUIDCEXTERN void storeConfigure(void);
SQUIDCEXTERN int storeCheckNegativeHit(StoreEntry *);
SQUIDCEXTERN void storeNegativeCache(StoreEntry *);
SQUIDCEXTERN void storeFreeMemory(void);
SQUIDCEXTERN int expiresMoreThan(time_t, time_t);
SQUIDCEXTERN int storeEntryValidToSend(StoreEntry *);
SQUIDCEXTERN void storeTimestampsSet(StoreEntry *);
SQUIDCEXTERN void storeRegisterAbort(StoreEntry * e, STABH * cb, void *);
SQUIDCEXTERN void storeUnregisterAbort(StoreEntry * e);
SQUIDCEXTERN void storeMemObjectDump(MemObject * mem);
SQUIDCEXTERN void storeEntryDump(const StoreEntry * e, int debug_lvl);
SQUIDCEXTERN const char *storeUrl(const StoreEntry *);
SQUIDCEXTERN void storeCreateMemObject(StoreEntry *, const char *, const char *);
SQUIDCEXTERN void storeCopyNotModifiedReplyHeaders(MemObject * O, MemObject * N);
SQUIDCEXTERN void storeBuffer(StoreEntry *);
SQUIDCEXTERN void storeBufferFlush(StoreEntry *);
SQUIDCEXTERN void storeHashInsert(StoreEntry * e, const cache_key *);
SQUIDCEXTERN void storeSetMemStatus(StoreEntry * e, mem_status_t);
#if STDC_HEADERS
SQUIDCEXTERN void
storeAppendPrintf(StoreEntry *, const char *,...) PRINTF_FORMAT_ARG2;
#else
SQUIDCEXTERN void storeAppendPrintf();
#endif
SQUIDCEXTERN void storeAppendVPrintf(StoreEntry *, const char *, va_list ap);
SQUIDCEXTERN int storeCheckCachable(StoreEntry * e);
SQUIDCEXTERN void storeSetPrivateKey(StoreEntry *);
SQUIDCEXTERN ssize_t objectLen(const StoreEntry * e);
SQUIDCEXTERN int contentLen(const StoreEntry * e);
SQUIDCEXTERN HttpReply *storeEntryReply(StoreEntry *);
SQUIDCEXTERN int storeTooManyDiskFilesOpen(void);
SQUIDCEXTERN void storeEntryReset(StoreEntry *);
SQUIDCEXTERN void storeHeapPositionUpdate(StoreEntry *, SwapDir *);
SQUIDCEXTERN void storeSwapFileNumberSet(StoreEntry * e, sfileno filn);
SQUIDCEXTERN void storeFsInit(void);
SQUIDCEXTERN void storeFsDone(void);
SQUIDCEXTERN void storeFsAdd(const char *, STSETUP *);
SQUIDCEXTERN void storeReplAdd(const char *, REMOVALPOLICYCREATE *);

/* store_modules.c */
SQUIDCEXTERN void storeFsSetup(void);

#endif /* SQUID_STORE_H */
