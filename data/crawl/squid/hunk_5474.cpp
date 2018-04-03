 #include "Store.h"
 #include "ufscommon.h"
 
+#include "SwapDir.h"
 
-static DRCB storeUfsReadDone;
-static DWCB storeUfsWriteDone;
-static void storeUfsIOCallback(storeIOState * sio, int errflag);
-static CBDUNL storeUfsIOFreeEntry;
+UfsIO UfsIO::Instance;
+bool
+UfsIO::shedLoad()
+{
+    return false;
+}
+void
+UfsIO::deleteSelf() const
+{
+    /* Do nothing, we use a single instance */
+}
+
+StoreIOState::Pointer
+UfsIO::createState(SwapDir *SD, StoreEntry *e, STIOCB * callback, void *callback_data) const
+{
+    return new ufsstate_t (SD, e, callback, callback_data);
+}
+
+DiskFile::Pointer 
+UfsIO::newFile (char const *path)
+{
+    return new UFSFile (path);
+}
 
-CBDATA_TYPE(storeIOState);
+CBDATA_CLASS_INIT(ufsstate_t);
 
-/* === PUBLIC =========================================================== */
+void *
+ufsstate_t::operator new (size_t)
+{
+    CBDATA_INIT_TYPE(ufsstate_t);
+    ufsstate_t *result = cbdataAlloc(ufsstate_t);
+    /* Mark result as being owned - we want the refcounter to do the delete
+     * call */
+    cbdataReference(result);
+    return result;
+}
+ 
+void
+ufsstate_t::operator delete (void *address)
+{
+    ufsstate_t *t = static_cast<ufsstate_t *>(address);
+    cbdataFree(address);
+    /* And allow the memory to be freed */
+    cbdataReferenceDone (t);
+}
+    
+ufsstate_t::ufsstate_t(SwapDir * SD, StoreEntry * anEntry, STIOCB * callback_, void *callback_data_) 
+{
+    swap_filen = anEntry->swap_filen;
+    swap_dirn = SD->index;
+    mode = O_BINARY;
+    callback = callback_;
+    callback_data = cbdataReference(callback_data_);
+    e = anEntry;
+}
 
-storeIOState *
-storeUfsOpen(SwapDir * SD, StoreEntry * e, STFNCB * file_callback,
-    STIOCB * callback, void *callback_data)
+CBDATA_CLASS_INIT(UFSFile);
+void *
+UFSFile::operator new (size_t)
 {
-    sfileno f = e->swap_filen;
-    char *path = commonUfsDirFullPath(SD, f, NULL);
-    storeIOState *sio;
-    struct stat sb;
-    int fd;
-    debug(79, 3) ("storeUfsOpen: fileno %08X\n", f);
-    fd = file_open(path, O_RDONLY | O_BINARY);
+    CBDATA_INIT_TYPE(UFSFile);
+    UFSFile *result = cbdataAlloc(UFSFile);
+    /* Mark result as being owned - we want the refcounter to do the delete
+     * call */
+    cbdataReference(result);
+    return result;
+}
+ 
+void
+UFSFile::operator delete (void *address)
+{
+    UFSFile *t = static_cast<UFSFile *>(address);
+    cbdataFree(address);
+    /* And allow the memory to be freed */
+    cbdataReferenceDone (t);
+}
+
+void
+UFSFile::deleteSelf() const {delete this;}
+
+UFSFile::UFSFile (char const *aPath) : fd (-1)
+{
+    assert (aPath);
+    debug (79,0)("UFSFile::UFSFile: %s\n", aPath);
+    path_ = xstrdup (aPath);
+}
+
+UFSFile::~UFSFile()
+{
+    safe_free (path_);
+    doClose();
+}
+
+void
+UFSFile::open (int flags, mode_t mode, IORequestor::Pointer callback)
+{
+    /* Simulate async calls */
+    fd = file_open(path_ , flags);
+    ioRequestor = callback;
     if (fd < 0) {
-	debug(79, 3) ("storeUfsOpen: got failure (%d)\n", errno);
-	return NULL;
+	debug(79, 3) ("UFSFile::open: got failure (%d)\n", errno);
+    } else {
+	store_open_disk_fd++;
+        debug(79, 3) ("UFSFile::open: opened FD %d\n", fd);
     }
-    debug(79, 3) ("storeUfsOpen: opened FD %d\n", fd);
-    CBDATA_INIT_TYPE_FREECB(storeIOState, storeUfsIOFreeEntry);
-    sio = cbdataAlloc(storeIOState);
-    sio->fsstate = memPoolAlloc(ufs_state_pool);
-
-    sio->swap_filen = f;
-    sio->swap_dirn = SD->index;
-    sio->mode = O_RDONLY | O_BINARY;
-    sio->callback = callback;
-    sio->callback_data = cbdataReference(callback_data);
-    sio->e = e;
-    ((ufsstate_t *) (sio->fsstate))->fd = fd;
-    ((ufsstate_t *) (sio->fsstate))->flags.writing = 0;
-    ((ufsstate_t *) (sio->fsstate))->flags.reading = 0;
-    ((ufsstate_t *) (sio->fsstate))->flags.close_request = 0;
-    if (fstat(fd, &sb) == 0)
-	sio->st_size = sb.st_size;
-    store_open_disk_fd++;
-
-    /* We should update the heap/dlink position here ! */
-    return sio;
+    callback->ioCompletedNotification();
 }
 
-storeIOState *
-storeUfsCreate(SwapDir * SD, StoreEntry * e, STFNCB * file_callback, STIOCB * callback, void *callback_data)
+void
+UFSFile::create (int flags, mode_t mode, IORequestor::Pointer callback)
 {
-    storeIOState *sio;
-    int fd;
-    int mode = (O_WRONLY | O_CREAT | O_TRUNC | O_BINARY);
-    char *path;
-    squidufsinfo_t *ufsinfo = (squidufsinfo_t *) SD->fsdata;
-    sfileno filn;
-    sdirno dirn;
+    /* We use the same logic path for open */
+    open(flags, mode, callback);
+}
 
-    /* Allocate a number */
-    dirn = SD->index;
-    filn = commonUfsDirMapBitAllocate(SD);
-    ufsinfo->suggest = filn + 1;
-    /* Shouldn't we handle a 'bitmap full' error here? */
-    path = commonUfsDirFullPath(SD, filn, NULL);
 
-    debug(79, 3) ("storeUfsCreate: fileno %08X\n", filn);
-    fd = file_open(path, mode);
-    if (fd < 0) {
-	debug(79, 3) ("storeUfsCreate: got failure (%d)\n", errno);
-	return NULL;
+void UFSFile::doClose()
+{
+    if (fd > -1) {
+	file_close(fd);
+	store_open_disk_fd--;
+	fd = -1;
     }
-    debug(79, 3) ("storeUfsCreate: opened FD %d\n", fd);
-    CBDATA_INIT_TYPE_FREECB(storeIOState, storeUfsIOFreeEntry);
-    sio = cbdataAlloc(storeIOState);
-    sio->fsstate = memPoolAlloc(ufs_state_pool);
+}
 
-    sio->swap_filen = filn;
-    sio->swap_dirn = dirn;
-    sio->mode = mode;
-    sio->callback = callback;
-    sio->callback_data = cbdataReference(callback_data);
-    sio->e = (StoreEntry *) e;
-    ((ufsstate_t *) (sio->fsstate))->fd = fd;
-    ((ufsstate_t *) (sio->fsstate))->flags.writing = 0;
-    ((ufsstate_t *) (sio->fsstate))->flags.reading = 0;
-    ((ufsstate_t *) (sio->fsstate))->flags.close_request = 0;
-    store_open_disk_fd++;
+void
+UFSFile::close ()
+{
+    debug (79,0)("UFSFile::close: %p closing for %p\n", this, ioRequestor.getRaw());
+    doClose();
+    assert (ioRequestor.getRaw());
+    ioRequestor->closeCompleted();
+}
 
-    /* now insert into the replacement policy */
-    commonUfsDirReplAdd(SD, e);
-    return sio;
+bool
+UFSFile::canRead() const
+{
+    return fd > -1;
+}
+
+bool
+UFSFile::error() const
+{
+    if (fd < 0)
+	return true;
+    return false;
 }
 
 void
-storeUfsClose(SwapDir * SD, storeIOState * sio)
+ufsstate_t::ioCompletedNotification()
 {
-    ufsstate_t *ufsstate = (ufsstate_t *) sio->fsstate;
+    if (opening) {
+	opening = false;
+	/* There is no 'opened' callback */
+	return;
+    }
+    if (creating) {
+	creating = false;
+	return;
+    }
+    assert(0);
+}
 
-    debug(79, 3) ("storeUfsClose: dirno %d, fileno %08X, FD %d\n",
-	sio->swap_dirn, sio->swap_filen, ufsstate->fd);
-    if (ufsstate->flags.reading || ufsstate->flags.writing) {
-	ufsstate->flags.close_request = 1;
+void
+ufsstate_t::closeCompleted()
+{
+    doCallback(theFile->error() ? 0 : -1);
+}
+
+void
+ufsstate_t::close()
+{
+    debug(79, 3) ("storeUfsClose: dirno %d, fileno %08X\n",
+	swap_dirn, swap_filen);
+    closing = true;
+    if (!(reading || writing)) {
+        ((UFSFile *)theFile.getRaw())->close();
+    }
+}
+
+void
+UFSStoreState::read_(char *buf, size_t size, off_t offset, STRCB * callback, void *callback_data)
+{
+    assert(read.callback == NULL);
+    assert(read.callback_data == NULL);
+    assert(!reading);
+    assert(!closing);
+    assert (callback);
+    if (!theFile->canRead()) {
+	debug(79, 3) ("UFSStoreState::read_: queueing read because theFile can't read\n");
+	queueRead (buf, size, offset, callback, callback_data);
 	return;
     }
-    storeUfsIOCallback(sio, 0);
+    read.callback = callback;
+    read.callback_data = cbdataReference(callback_data);
+    debug(79, 3) ("UFSStoreState::read_: dirno %d, fileno %08X\n",
+	swap_dirn, swap_filen);
+    offset_ = offset;
+    read_buf = buf;
+    reading = true;
+    theFile->read(buf, offset, size);
 }
 
 void
-storeUfsRead(SwapDir * SD, storeIOState * sio, char *buf, size_t size, off_t offset, STRCB * callback, void *callback_data)
-{
-    ufsstate_t *ufsstate = (ufsstate_t *) sio->fsstate;
-
-    assert(sio->read.callback == NULL);
-    assert(sio->read.callback_data == NULL);
-    sio->read.callback = callback;
-    sio->read.callback_data = cbdataReference(callback_data);
-    debug(79, 3) ("storeUfsRead: dirno %d, fileno %08X, FD %d\n",
-	sio->swap_dirn, sio->swap_filen, ufsstate->fd);
-    sio->offset = offset;
-    ufsstate->flags.reading = 1;
-    file_read(ufsstate->fd,
-	buf,
-	size,
-	offset,
-	storeUfsReadDone,
-	sio);
+UFSFile::read(char *buf, off_t offset, size_t size)
+{
+    assert (fd > -1);
+    assert (ioRequestor.getRaw());
+    file_read(fd, buf, size, offset, ReadDone, this);
+}
+ 
+void
+UFSFile::ReadDone(int fd, const char *buf, int len, int errflag, void *my_data)
+{
+    UFSFile *myFile = static_cast<UFSFile *>(my_data);
+    assert (myFile);
+    myFile->readDone (fd, buf, len, errflag);
 }
 
 void
-storeUfsWrite(SwapDir * SD, storeIOState * sio, char *buf, size_t size, off_t offset, FREE * free_func)
+UFSFile::write(char const *buf, size_t size, off_t offset, FREE *free_func)
 {
-    ufsstate_t *ufsstate = (ufsstate_t *) sio->fsstate;
-    debug(79, 3) ("storeUfsWrite: dirn %d, fileno %08X, FD %d\n", sio->swap_dirn, sio->swap_filen, ufsstate->fd);
-    ufsstate->flags.writing = 1;
-    file_write(ufsstate->fd,
+    debug(79, 3) ("storeUfsWrite: FD %d\n",fd);
+    file_write(fd,
 	offset,
-	buf,
+	(char *)buf,
 	size,
-	storeUfsWriteDone,
-	sio,
+	WriteDone,
+	this,
 	free_func);
 }
 
 void
-storeUfsUnlink(SwapDir * SD, StoreEntry * e)
+UFSStoreState::write(char *buf, size_t size, off_t offset, FREE * free_func)
+{
+    debug(79, 3) ("UFSStoreState::write: dirn %d, fileno %08X\n", swap_dirn, swap_filen);
+    if (!theFile->canWrite() || writing) {
+	assert(creating || writing);
+	queueWrite(buf, size, offset, free_func);
+	return;
+    }
+    writing = true;
+    theFile->write(buf,size,offset,free_func);
+}
+
+void
+UfsSwapDir::unlink(StoreEntry & e)
 {
-    debug(79, 3) ("storeUfsUnlink: fileno %08X\n", e->swap_filen);
-    commonUfsDirReplRemove(e);
-    commonUfsDirMapBitReset(SD, e->swap_filen);
-    commonUfsDirUnlinkFile(SD, e->swap_filen);
+    debug(79, 3) ("storeUfsUnlink: fileno %08X\n", e.swap_filen);
+    replacementRemove(&e);
+    mapBitReset(e.swap_filen);
+    UFSSwapDir::unlinkFile(e.swap_filen);
 }
 
 /*  === STATIC =========================================================== */
 
-static void
-storeUfsReadDone(int fd, const char *buf, int len, int errflag, void *my_data)
+void
+UFSFile::readDone(int rvfd, const char *buf, int len, int errflag)
 {
-    storeIOState *sio = (storeIOState *)my_data;
-    ufsstate_t *ufsstate = (ufsstate_t *) sio->fsstate;
-    STRCB *callback;
-    void *cbdata;
-    ssize_t rlen;
+    debug (79,3)("UFSFile::readDone: FD %d\n",rvfd);
+    assert (fd == rvfd);
 
-    debug(79, 3) ("storeUfsReadDone: dirno %d, fileno %08X, FD %d, len %d\n",
-	sio->swap_dirn, sio->swap_filen, fd, len);
-    ufsstate->flags.reading = 0;
+    ssize_t rlen;
     if (errflag) {
-	debug(79, 3) ("storeUfsReadDone: got failure (%d)\n", errflag);
+	debug(79, 3) ("UFSFile::readDone: got failure (%d)\n", errflag);
 	rlen = -1;
     } else {
 	rlen = (ssize_t) len;
-	sio->offset += len;
     }
-    assert(sio->read.callback);
-    assert(sio->read.callback_data);
-    callback = sio->read.callback;
-    sio->read.callback = NULL;
-    if (cbdataReferenceValidDone(sio->read.callback_data, &cbdata))
-	callback(cbdata, buf, (size_t) rlen);
-}
-
-static void
-storeUfsWriteDone(int fd, int errflag, size_t len, void *my_data)
-{
-    storeIOState *sio = (storeIOState *)my_data;
-    ufsstate_t *ufsstate = (ufsstate_t *) sio->fsstate;
-    debug(79, 3) ("storeUfsWriteDone: dirno %d, fileno %08X, FD %d, len %ld\n",
-	sio->swap_dirn, sio->swap_filen, fd, (long int) len);
-    ufsstate->flags.writing = 0;
+    if (errflag == DISK_EOF)
+	errflag = DISK_OK;	/* EOF is signalled by len == 0, not errors... */
+    ioRequestor->readCompleted(buf, rlen, errflag);
+}
+
+void
+ufsstate_t::readCompleted(const char *buf, int len, int errflag)
+{
+
+    reading = false;
+    debug(79, 3) ("storeUfsReadDone: dirno %d, fileno %08X, len %d\n",
+	swap_dirn, swap_filen, len);
+    if (len > 0)
+	offset_ += len;
+    STRCB *callback = read.callback;
+    assert(callback);
+    read.callback = NULL;
+    void *cbdata;
+    if (!closing && cbdataReferenceValidDone(read.callback_data, &cbdata)) {
+	if (len > 0 && read_buf != buf)
+	    memcpy(read_buf, buf, len);
+	callback(cbdata, read_buf, len);
+    }
+    if (closing)
+	fatal("Sync ufs doesn't support overlapped close and read calls\n");
+}
+
+void
+UFSFile::WriteDone (int fd, int errflag, size_t len, void *me)
+{
+    UFSFile *aFile = static_cast<UFSFile *>(me);
+    aFile->writeDone (fd, errflag, len);
+}
+
+void
+UFSFile::writeDone(int rvfd, int errflag, size_t len)
+{
+    assert (rvfd == fd);
+    debug(79, 3) ("storeUfsWriteDone: FD %d, len %ld\n",
+	fd, (long int) len);
     if (errflag) {
 	debug(79, 0) ("storeUfsWriteDone: got failure (%d)\n", errflag);
-	storeUfsIOCallback(sio, errflag);
+	doClose();
+	ioRequestor->writeCompleted (DISK_ERROR,0);
 	return;
     }
-    sio->offset += len;
-    if (ufsstate->flags.close_request)
-	storeUfsIOCallback(sio, errflag);
+    ioRequestor->writeCompleted(DISK_OK, len);
 }
 
-static void
-storeUfsIOCallback(storeIOState * sio, int errflag)
+void
+ufsstate_t::writeCompleted(int errflag, size_t len)
+{
+    debug(79, 3) ("storeUfsWriteDone: dirno %d, fileno %08X, len %ld\n",
+	swap_dirn, swap_filen, (long int) len);
+    writing = false;
+    if (theFile->error())
+	doCallback(DISK_ERROR);
+    offset_ += len;
+    if (closing)
+        ((UFSFile *)theFile.getRaw())->close();
+}
+
+void
+ufsstate_t::doCallback(int errflag)
 {
-    ufsstate_t *ufsstate = (ufsstate_t *) sio->fsstate;
-    void *cbdata;
     debug(79, 3) ("storeUfsIOCallback: errflag=%d\n", errflag);
-    if (ufsstate->fd > -1) {
-	file_close(ufsstate->fd);
-	store_open_disk_fd--;
-    }
-    if (cbdataReferenceValidDone(sio->callback_data, &cbdata))
-	sio->callback(cbdata, errflag, sio);
-    sio->callback = NULL;
-    cbdataFree(sio);
+    /* We are finished with the file */
+    theFile = NULL;
+    void *cbdata;
+    if (cbdataReferenceValidDone(callback_data, &cbdata))
+	callback(cbdata, errflag, this);
+    callback = NULL;
 }
 
 
 /*
  * Clean up any references from the SIO before it get's released.
  */
-static void
-storeUfsIOFreeEntry(void *sio)
+ufsstate_t::~ufsstate_t()
+{}
+
+
+
+/* ============= THE REAL UFS CODE ================ */
+
+UFSStoreState::UFSStoreState() : opening (false), creating (false), closing (false), reading(false), writing(false), pending_reads(NULL), pending_writes (NULL){}
+UFSStoreState::~UFSStoreState()
+{
+    _queued_read *qr;
+    while ((qr = (_queued_read *)linklistShift(&pending_reads))) {
+	cbdataReferenceDone(qr->callback_data);
+	delete qr;
+    }
+
+    struct _queued_write *qw;
+    while ((qw = (struct _queued_write *)linklistShift(&pending_writes))) {
+	if (qw->free_func)
+	    qw->free_func(qw->buf);
+	delete qw;
+    }
+}
+
+bool
+UFSStoreState::kickReadQueue()
+{
+    _queued_read *q = (_queued_read *)linklistShift(&pending_reads);
+    if (NULL == q)
+	return false;
+    debug(79, 3) ("UFSStoreState::kickReadQueue: reading queued request of %ld bytes\n",
+	(long int) q->size);
+    void *cbdata;
+    if (cbdataReferenceValidDone(q->callback_data, &cbdata))
+	read_(q->buf, q->size, q->offset, q->callback, cbdata);
+    delete q;
+    return true;
+}
+
+MemPool * UFSStoreState::_queued_read::Pool = NULL;
+
+void *
+UFSStoreState::_queued_read::operator new(size_t size)
+{
+    if (!Pool)
+	Pool = memPoolCreate("AUFS Queued read data",sizeof (_queued_read));
+    return memPoolAlloc (Pool);
+}
+
+void
+UFSStoreState::_queued_read::operator delete (void *address)
+{
+    memPoolFree (Pool, address);
+}
+
+void
+UFSStoreState::queueRead(char *buf, size_t size, off_t offset, STRCB *callback, void *callback_data)
+{
+    debug(79, 3) ("UFSStoreState::queueRead: queueing read\n");
+    assert(opening);
+    assert (pending_reads == NULL);
+    _queued_read *q = new _queued_read;
+    q->buf = buf;
+    q->size = size;
+    q->offset = offset;
+    q->callback = callback;
+    q->callback_data = cbdataReference(callback_data);
+    linklistPush(&pending_reads, q);
+}
+
+MemPool * UFSStoreState::_queued_write::Pool = NULL;
+
+void *
+UFSStoreState::_queued_write::operator new(size_t size)
+{
+    if (!Pool)
+	Pool = memPoolCreate("AUFS Queued write data",sizeof (_queued_write));
+    return memPoolAlloc (Pool);
+}
+
+void
+UFSStoreState::_queued_write::operator delete (void *address)
+{
+    memPoolFree (Pool, address);
+}
+
+bool
+UFSStoreState::kickWriteQueue()
 {
-    memPoolFree(ufs_state_pool, ((storeIOState *) sio)->fsstate);
+    _queued_write *q = (_queued_write *)linklistShift(&pending_writes);
+    if (NULL == q)
+	return false;
+    debug(79, 3) ("storeAufsKickWriteQueue: writing queued chunk of %ld bytes\n",
+	(long int) q->size);
+    write(q->buf, q->size, q->offset, q->free_func);
+    delete q;
+    return true;
+}
+
+void
+UFSStoreState::queueWrite(char *buf, size_t size, off_t offset, FREE * free_func)
+{
+    debug(79, 3) ("UFSStoreState::queueWrite: queuing write\n");
+    struct _queued_write *q;
+    q = new _queued_write;
+    q->buf = buf;
+    q->size = size;
+    q->offset = offset;
+    q->free_func = free_func;
+    linklistPush(&pending_writes, q);
+}
+
+StoreIOState::Pointer
+UFSStrategy::open(SwapDir * SD, StoreEntry * e, STFNCB * file_callback,
+		  STIOCB * callback, void *callback_data)
+{
+    assert (((UfsSwapDir *)SD)->IO == this);
+    debug(79, 3) ("UFSStrategy::open: fileno %08X\n", e->swap_filen);
+    if (shedLoad()) {
+	openFailed();
+	return NULL;
+    }
+    /* to consider: make createstate a private UFSStrategy call */
+    StoreIOState::Pointer sio = createState (SD, e, callback, callback_data);
+    
+    sio->mode |= O_RDONLY;
+    
+    UFSStoreState *state = dynamic_cast <UFSStoreState *>(sio.getRaw());
+    assert (state);
+    char *path = ((UFSSwapDir *)SD)->fullPath(e->swap_filen, NULL);
+
+    DiskFile::Pointer myFile = newFile (path);
+    
+    state->theFile = myFile;
+    state->opening = true;
+    myFile->open (sio->mode, 0644, state);
+    if (myFile->error())
+	return NULL;
+    
+    return sio;
+}
+
+StoreIOState::Pointer
+UFSStrategy::create(SwapDir * SD, StoreEntry * e, STFNCB * file_callback,
+		  STIOCB * callback, void *callback_data)
+{
+    assert (((UfsSwapDir *)SD)->IO == this);
+    /* Allocate a number */
+    sfileno filn = ((UFSSwapDir *)SD)->mapBitAllocate();
+    debug(79, 3) ("UFSStrategy::create: fileno %08X\n", filn);
+    if (shedLoad()) {
+	openFailed();
+	((UFSSwapDir *)SD)->mapBitReset (filn);
+	return NULL;
+    }
+    
+    /* Shouldn't we handle a 'bitmap full' error here? */
+
+    StoreIOState::Pointer sio = createState (SD, e, callback, callback_data);
+
+    sio->mode |= O_WRONLY | O_CREAT | O_TRUNC;
+    sio->swap_filen = filn;
+
+    UFSStoreState *state = dynamic_cast <UFSStoreState *>(sio.getRaw());
+    assert (state);
+    char *path = ((UFSSwapDir *)SD)->fullPath(filn, NULL);
+    
+    DiskFile::Pointer myFile = newFile (path);
+    
+    state->theFile = myFile;
+    state->creating = true;
+    myFile->create (state->mode, 0644, state);
+    if (myFile->error()) {
+	((UFSSwapDir *)SD)->mapBitReset (filn);
+	return NULL;
+    }
+    
+    /* now insert into the replacement policy */
+    ((UFSSwapDir *)SD)->replacementAdd(e);
+    return sio;
 }
