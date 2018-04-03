+
+/*
+ * $Id: MemObject.cc,v 1.1 2003/01/23 00:37:14 robertc Exp $
+ *
+ * DEBUG: section 19    Store Memory Primitives
+ * AUTHOR: Robert Collins
+ *
+ * SQUID Web Proxy Cache          http://www.squid-cache.org/
+ * ----------------------------------------------------------
+ *
+ *  Squid is the result of efforts by numerous individuals from
+ *  the Internet community; see the CONTRIBUTORS file for full
+ *  details.   Many organizations have provided support for Squid's
+ *  development; see the SPONSORS file for full details.  Squid is
+ *  Copyrighted (C) 2001 by the Regents of the University of
+ *  California; see the COPYRIGHT file for full details.  Squid
+ *  incorporates software developed and/or copyrighted by other
+ *  sources; see the CREDITS file for full details.
+ *
+ *  This program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2 of the License, or
+ *  (at your option) any later version.
+ *  
+ *  This program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ *  GNU General Public License for more details.
+ *  
+ *  You should have received a copy of the GNU General Public License
+ *  along with this program; if not, write to the Free Software
+ *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
+ *
+ */
+
+#include "squid.h"
+#include "MemObject.h"
+#include "HttpRequest.h"
+#include "HttpReply.h"
+#include "Store.h"
+#include "StoreClient.h"
+#include "Generic.h"
+
+/* TODO: make this global or private */
+#if URL_CHECKSUM_DEBUG
+static unsigned int url_checksum(const char *url);
+unsigned int
+url_checksum(const char *url)
+{
+    unsigned int ck;
+    MD5_CTX M;
+    static unsigned char digest[16];
+    MD5Init(&M);
+    MD5Update(&M, (unsigned char *) url, strlen(url));
+    MD5Final(digest, &M);
+    xmemcpy(&ck, digest, sizeof(ck));
+    return ck;
+}
+#endif
+
+MemPool *MemObject::pool = NULL;
+
+void *
+MemObject::operator new (size_t byteCount)
+{
+    /* derived classes with different sizes must implement their own new */
+    assert (byteCount == sizeof (MemObject));
+    if (!pool)
+	pool = memPoolCreate("MemObject", sizeof (MemObject));
+    return memPoolAlloc(pool);
+}
+
+void
+MemObject::operator delete (void *address)
+{
+    memPoolFree(pool, address);
+}
+
+size_t
+MemObject::inUseCount()
+{
+    if (!pool)
+	return 0;
+    MemPoolStats stats;
+    memPoolGetStats (&stats, pool);
+    return stats.items_inuse;
+}
+
+MemObject::MemObject(char const *aUrl, char const *aLog_url) :
+_reply (httpReplyCreate())
+{
+    url = xstrdup(aUrl);
+#if URL_CHECKSUM_DEBUG
+    chksum = url_checksum(url);
+#endif
+    log_url = xstrdup(aLog_url);
+    object_sz = -1;
+    fd = -1;
+    /* XXX account log_url */
+    debug(20, 3) ("MemObject::MemObject: initialized %p\n", this);
+}
+
+MemObject::~MemObject()
+{
+    const Ctx ctx = ctx_enter(url);
+    debug(20, 3) ("destroy_MemObject: destroying %p\n", this);
+#if URL_CHECKSUM_DEBUG
+    assert(chksum == url_checksum(url));
+#endif
+    if (!shutting_down)
+        assert(swapout.sio == NULL);
+    data_hdr.freeContent();
+    /*
+     * There is no way to abort FD-less clients, so they might
+     * still have mem->clients set if mem->fd == -1
+     */
+    assert(fd == -1 || clients.head == NULL);
+    httpReplyDestroy((HttpReply *)_reply);
+    requestUnlink(request);
+    request = NULL;
+    ctx_exit(ctx);              /* must exit before we free mem->url */
+    safe_free(url);
+    safe_free(log_url);    /* XXX account log_url */
+    safe_free(vary_headers);
+}
+
+void
+MemObject::unlinkRequest()
+{
+    /* XXX Should we assert(request)? */
+    requestUnlink(request);
+    request = NULL;
+}
+
+void
+MemObject::write ( StoreIOBuffer writeBuffer, STMCB *callback, void *callbackData)
+{
+    debug(19, 6) ("memWrite: offset %lu len %d\n", writeBuffer.offset, writeBuffer.length);
+
+    /* the offset is into the content, not the headers */
+    writeBuffer.offset += (_reply ? _reply->hdr_sz : 0);
+
+    /* We don't separate out mime headers yet, so ensure that the first
+     * write is at offset 0 - where they start 
+     */
+    assert (data_hdr.endOffset() || writeBuffer.offset == 0);
+
+    assert (data_hdr.write (writeBuffer));
+    callback (callbackData, writeBuffer);
+}
+
+void
+MemObject::dump() const
+{
+    debug(20, 1) ("MemObject->data.head: %p\n",
+	data_hdr.head);
+    debug(20, 1) ("MemObject->data.tail: %p\n",
+	data_hdr.tail);
+#if 0
+    /* do we want this one? */
+    debug(20, 1) ("MemObject->data.origin_offset: %d\n",
+	data_hdr.head ? data_hdr.head->nodeBuffer.offset : 0);
+#endif
+    debug(20, 1) ("MemObject->start_ping: %d.%06d\n",
+	(int) start_ping.tv_sec,
+	(int) start_ping.tv_usec);
+    debug(20, 1) ("MemObject->inmem_hi: %d\n",
+	(int) data_hdr.endOffset());
+    debug(20, 1) ("MemObject->inmem_lo: %d\n",
+	(int) inmem_lo);
+    debug(20, 1) ("MemObject->nclients: %d\n",
+	nclients);
+    debug(20, 1) ("MemObject->reply: %p\n",
+	_reply);
+    debug(20, 1) ("MemObject->request: %p\n",
+	request);
+    debug(20, 1) ("MemObject->log_url: %p %s\n",
+	log_url,
+	checkNullString(log_url));
+}
+
+HttpReply const *
+MemObject::getReply() const
+{
+    return _reply;
+}
+
+struct LowestMemReader : public unary_function<store_client, void>
+{
+    LowestMemReader(off_t seed):current(seed){}
+    void operator() (store_client const &x) 
+      { 
+	if (x.memReaderHasLowerOffset(current))
+	    current = x.copyInto.offset; }
+    off_t current;
+};
+
+struct StoreClientStats : public unary_function<store_client, void>
+{
+    StoreClientStats(StoreEntry *anEntry):where(anEntry),index(0){}
+    void operator()(store_client const &x) {
+	x.dumpStats(where, index++);
+    }
+    StoreEntry *where;
+    size_t index;
+};
+
+void
+MemObject::stat (StoreEntry *s) const
+{
+    storeAppendPrintf(s, "\t%s %s\n",
+	RequestMethodStr[method], log_url);
+    storeAppendPrintf(s, "\tinmem_lo: %d\n", (int) inmem_lo);
+    storeAppendPrintf(s, "\tinmem_hi: %d\n", (int) data_hdr.endOffset());
+    storeAppendPrintf(s, "\tswapout: %d bytes queued\n",
+	(int) swapout.queue_offset);
+    if (swapout.sio.getRaw())
+	storeAppendPrintf(s, "\tswapout: %d bytes written\n",
+	    (int) swapout.sio->offset());
+    StoreClientStats statsVisitor(s);
+    for_each(clients, statsVisitor);
+}
+
+off_t
+MemObject::endOffset () const
+{
+    return data_hdr.endOffset();
+}
+
+size_t
+MemObject::size() const
+{
+    if (object_sz < 0) 
+	return endOffset();
+    return object_sz;
+}
+
+void
+MemObject::reset()
+{
+    assert(swapout.sio == NULL);
+    data_hdr.freeContent();
+    inmem_lo = 0;
+    /* Should we check for clients? */
+}
+
+
+off_t
+MemObject::lowestMemReaderOffset() const
+{
+    LowestMemReader lowest (endOffset() + 1);
+
+    for_each (clients, lowest);
+    
+    return lowest.current;
+}
+
+/* XXX: This is wrong. It breaks *badly* on range combining */
+bool
+MemObject::readAheadPolicyCanRead() const
+{
+    return (size_t)endOffset() - getReply()->hdr_sz < lowestMemReaderOffset() + Config.readAheadGap;
+}
+
+void
+MemObject::addClient(store_client *aClient)
+{
+    ++nclients;
+    dlinkAdd(aClient, &aClient->node, &clients);
+}
+
+#if URL_CHECKSUM_DEBUG
+void
+MemObject::checkUrlChecksum () const
+{
+    assert(chksum == url_checksum(url));
+}
+#endif
+
+/*
+ * How much of the object data is on the disk?
+ */
+size_t
+MemObject::objectBytesOnDisk() const
+{
+    /*
+     * NOTE: storeOffset() represents the disk file size,
+     * not the amount of object data on disk.
+     * 
+     * If we don't have at least 'swap_hdr_sz' bytes
+     * then none of the object data is on disk.
+     *
+     * This should still be safe if swap_hdr_sz == 0,
+     * meaning we haven't even opened the swapout file
+     * yet.
+     */
+    if (swapout.sio.getRaw() == NULL)
+	return 0;
+    off_t nwritten = swapout.sio->offset();
+    if (nwritten <= (off_t)swap_hdr_sz)
+	return 0;
+    return (size_t) (nwritten - swap_hdr_sz);
+}
+
+off_t
+MemObject::policyLowestOffsetToKeep() const
+{
+    /*
+     * Careful.  lowest_offset can be greater than endOffset(), such
+     * as in the case of a range request.
+     */
+    off_t lowest_offset = lowestMemReaderOffset();
+    if (endOffset() < lowest_offset ||
+	endOffset() - inmem_lo > (ssize_t)Config.Store.maxInMemObjSize)
+	return lowest_offset;
+    
+    return inmem_lo;
+}
+
+void
+MemObject::trimSwappable()
+{
+    off_t new_mem_lo = policyLowestOffsetToKeep();
+    /*
+     * We should only free up to what we know has been written
+     * to disk, not what has been queued for writing.  Otherwise
+     * there will be a chunk of the data which is not in memory
+     * and is not yet on disk.
+     * The -1 makes sure the page isn't freed until storeSwapOut has
+     * walked to the next page. (mem->swapout.memnode)
+     */
+    off_t on_disk;
+    if ((on_disk = objectBytesOnDisk()) - 1 < new_mem_lo)
+	new_mem_lo = on_disk - 1;
+    if (new_mem_lo == -1)
+	new_mem_lo = 0;	/* the above might become -1 */
+    data_hdr.freeDataUpto(new_mem_lo);
+    inmem_lo = new_mem_lo;
+}
+
+void
+MemObject::trimUnSwappable()
+{
+    off_t new_mem_lo = policyLowestOffsetToKeep();
+    assert (new_mem_lo > 0);
+
+    data_hdr.freeDataUpto(new_mem_lo);
+    inmem_lo = new_mem_lo;
+}
+
+
+bool
+MemObject::isContiguous() const
+{
+    bool result = data_hdr.hasContigousContentRange (inmem_lo, endOffset());
+    /* XXX : make this higher level */
+    debug (19, result ? 2 : 1) ("MemObject::isContiguous: Returning %s\n",
+				result ? "true" : "false");
+    return result;
+}
