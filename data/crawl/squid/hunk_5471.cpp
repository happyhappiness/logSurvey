 #include <sys/shm.h>
 
 #include "store_diskd.h"
+#include "SwapDir.h"
 
-static int storeDiskdSend(int, SwapDir *, int, storeIOState *, int, int, off_t);
-static void storeDiskdIOCallback(storeIOState * sio, int errflag);
-static CBDUNL storeDiskdIOFreeEntry;
-
-CBDATA_TYPE(storeIOState);
+static int storeDiskdSend(int, DiskdIO *, int, StoreIOState::Pointer, int, int, off_t);
+static int storeDiskdSend(int, DiskdIO *, int, DiskdFile *, int, int, off_t);
 
 /* === PUBLIC =========================================================== */
+DiskdIO::DiskdIO() : away (0), magic1(64), magic2(72)
+{
+}
 
-storeIOState *
-storeDiskdOpen(SwapDir * SD, StoreEntry * e, STFNCB * file_callback,
-    STIOCB * callback, void *callback_data)
+bool
+DiskdIO::shedLoad()
 {
-    sfileno f = e->swap_filen;
-    int x;
-    storeIOState *sio;
-    char *buf;
-    diskdstate_t *diskdstate;
-    off_t shm_offset;
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)SD->fsdata;
-    debug(79, 3) ("storeDiskdOpen: fileno %08X\n", f);
     /*
      * Fail on open() if there are too many requests queued.
      */
-    if (diskdinfo->away > diskdinfo->magic1) {
-	debug(79, 3) ("storeDiskdOpen: FAILING, too many requests away\n");
-	diskd_stats.open_fail_queue_len++;
-	return NULL;
+    if (away > magic1) {
+	debug(79, 3) ("storeDiskdIO::sheLoad: Shedding, too many requests away\n");
+
+	return true;
+    }
+    return false;
+}
+
+int
+DiskdIO::load()
+{
+    /* Calculate the storedir load relative to magic2 on a scale of 0 .. 1000 */
+    /* the parse function guarantees magic2 is positivie */
+    return away * 1000 / magic2;
+}
+
+void
+DiskdIO::deleteSelf() const
+{
+    /* do nothing, we use a single instance */
+}
+
+void
+DiskdIO::openFailed()
+{
+    diskd_stats.open_fail_queue_len++;
+}
+
+StoreIOState::Pointer
+DiskdIO::createState(SwapDir *SD, StoreEntry *e, STIOCB * callback, void *callback_data) const
+{
+    return new diskdstate_t (SD, e, callback, callback_data);
+}
+
+DiskFile::Pointer
+DiskdIO::newFile (char const *path)
+{
+    return new DiskdFile (path, this);
+}
+
+
+/*
+ * SHM manipulation routines
+ */
+void
+SharedMemory::put (off_t offset)
+{
+    int i;
+    assert(offset >= 0);
+    assert(offset < nbufs * SHMBUF_BLKSZ);
+    i = offset / SHMBUF_BLKSZ;
+    assert(i < nbufs);
+    assert(CBIT_TEST(inuse_map, i));
+    CBIT_CLR(inuse_map, i);
+    --diskd_stats.shmbuf_count;
+}
+
+void *
+SharedMemory::get (off_t * shm_offset)
+{
+    char *aBuf = NULL;
+    int i;
+    for (i = 0; i < nbufs; i++) {
+	if (CBIT_TEST(inuse_map, i))
+	    continue;
+	CBIT_SET(inuse_map, i);
+	*shm_offset = i * SHMBUF_BLKSZ;
+	aBuf = buf + (*shm_offset);
+	break;
     }
-    CBDATA_INIT_TYPE_FREECB(storeIOState, storeDiskdIOFreeEntry);
-    sio = cbdataAlloc(storeIOState);
-    sio->fsstate = diskdstate = (diskdstate_t *)memPoolAlloc(diskd_state_pool);
-
-    sio->swap_filen = f;
-    sio->swap_dirn = SD->index;
-    sio->mode = O_RDONLY | O_BINARY;
-    sio->callback = callback;
-    sio->callback_data = cbdataReference(callback_data);
-    sio->e = e;
-
-    diskdstate->flags.writing = 0;
-    diskdstate->flags.reading = 0;
-    diskdstate->flags.close_request = 0;
-    diskdstate->id = diskd_stats.sio_id++;
-
-    buf = (char *)storeDiskdShmGet(SD, &shm_offset);
-    xstrncpy(buf, commonUfsDirFullPath(SD, f, NULL), SHMBUF_BLKSZ);
-    x = storeDiskdSend(_MQD_OPEN,
-	SD,
-	diskdstate->id,
-	sio,
+    assert(aBuf);
+    assert(aBuf >= buf);
+    assert(aBuf < buf + (nbufs * SHMBUF_BLKSZ));
+    diskd_stats.shmbuf_count++;
+    if (diskd_stats.max_shmuse < diskd_stats.shmbuf_count)
+	diskd_stats.max_shmuse = diskd_stats.shmbuf_count;
+    return aBuf;
+}
+
+void
+SharedMemory::init(int ikey, int magic2)
+{
+    nbufs = (int)(magic2 * 1.3);
+    id = shmget((key_t) (ikey + 2),
+	nbufs * SHMBUF_BLKSZ, 0600 | IPC_CREAT);
+    if (id < 0) {
+	debug(50, 0) ("storeDiskdInit: shmget: %s\n", xstrerror());
+	fatal("shmget failed");
+    }
+    buf = (char *)shmat(id, NULL, 0);
+    if (buf == (void *) -1) {
+	debug(50, 0) ("storeDiskdInit: shmat: %s\n", xstrerror());
+	fatal("shmat failed");
+    }
+    inuse_map = (char *)xcalloc((nbufs + 7) / 8, 1);
+    diskd_stats.shmbuf_count += nbufs;
+    for (int i = 0; i < nbufs; i++) {
+	CBIT_SET(inuse_map, i);
+	put (i * SHMBUF_BLKSZ);
+    }
+}
+
+CBDATA_CLASS_INIT(DiskdFile);
+
+void *
+DiskdFile::operator new (size_t)
+{
+    CBDATA_INIT_TYPE(DiskdFile);
+    DiskdFile *result = cbdataAlloc(DiskdFile);
+    /* Mark result as being owned - we want the refcounter to do the delete
+     * call */
+    cbdataReference(result);
+    debug (0,0)("diskdFile with base %p allocating\n", result);
+    return result;
+}
+ 
+void
+DiskdFile::operator delete (void *address)
+{
+    debug (0,0)("diskdFile with base %p deleting\n",address);
+    DiskdFile *t = static_cast<DiskdFile *>(address);
+    cbdataFree(address);
+    /* And allow the memory to be freed */
+    cbdataReferenceDone (t);
+}
+
+void
+DiskdFile::deleteSelf() const {delete this;}
+
+DiskdFile::DiskdFile (char const *aPath, DiskdIO *anIO) : errorOccured (false), IO(anIO)
+{
+    assert (aPath);
+    debug (79,0)("DiskdFile::DiskdFile: %s\n", aPath);
+    path_ = xstrdup (aPath);
+    id = diskd_stats.sio_id++;
+}
+
+DiskdFile::~DiskdFile()
+{
+    safe_free (path_);
+}
+
+void
+DiskdFile::open (int flags, mode_t aMode, IORequestor::Pointer callback)
+{
+    debug (79,0)("DiskdFile::open: %p opening for %p\n", this, callback.getRaw());
+    assert (ioRequestor.getRaw() == NULL);
+    ioRequestor = callback;
+    assert (callback.getRaw());
+    mode = flags;
+    off_t shm_offset;
+    char *buf = (char *)IO->shm.get(&shm_offset);
+    xstrncpy(buf, path_, SHMBUF_BLKSZ);
+    int x = storeDiskdSend(_MQD_OPEN,
+	IO,
+	id,
+	this,
 	strlen(buf) + 1,
-	O_RDONLY,
+	mode,
 	shm_offset);
     if (x < 0) {
-	debug(79, 1) ("storeDiskdSend OPEN: %s\n", xstrerror());
-	storeDiskdShmPut(SD, shm_offset);
-	cbdataReferenceDone(sio->callback_data);
-	cbdataFree(sio);
-	return NULL;
+	errorOccured = true;
+	IO->shm.put (shm_offset);
+	ioRequestor->ioCompletedNotification();
+	ioRequestor = NULL;
     }
     diskd_stats.open.ops++;
-    return sio;
 }
 
-storeIOState *
-storeDiskdCreate(SwapDir * SD, StoreEntry * e, STFNCB * file_callback,
-    STIOCB * callback, void *callback_data)
-{
-    sfileno f;
-    int x;
-    storeIOState *sio;
-    char *buf;
+void
+DiskdFile::create (int flags, mode_t aMode, IORequestor::Pointer callback){
+    debug (79,0)("DiskdFile::create: %p creating for %p\n", this, callback.getRaw());
+    assert (ioRequestor.getRaw() == NULL);
+    ioRequestor = callback;
+    assert (callback.getRaw());
+    mode = flags;
     off_t shm_offset;
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)SD->fsdata;
-    diskdstate_t *diskdstate;
-    /*
-     * Fail on open() if there are too many requests queued.
-     */
-    if (diskdinfo->away > diskdinfo->magic1) {
-	diskd_stats.open_fail_queue_len++;
-	return NULL;
-    }
-    /* Allocate a number */
-    f = commonUfsDirMapBitAllocate(SD);
-    debug(79, 3) ("storeDiskdCreate: fileno %08X\n", f);
-
-    CBDATA_INIT_TYPE_FREECB(storeIOState, storeDiskdIOFreeEntry);
-    sio = cbdataAlloc(storeIOState);
-    sio->fsstate = diskdstate = (diskdstate_t *)memPoolAlloc(diskd_state_pool);
-
-    sio->swap_filen = f;
-    sio->swap_dirn = SD->index;
-    sio->mode = O_WRONLY | O_CREAT | O_TRUNC;
-    sio->callback = callback;
-    sio->callback_data = cbdataReference(callback_data);
-    sio->e = e;
-
-    diskdstate->flags.writing = 0;
-    diskdstate->flags.reading = 0;
-    diskdstate->flags.close_request = 0;
-    diskdstate->id = diskd_stats.sio_id++;
-
-    buf = (char *)storeDiskdShmGet(SD, &shm_offset);
-    xstrncpy(buf, commonUfsDirFullPath(SD, f, NULL), SHMBUF_BLKSZ);
-    x = storeDiskdSend(_MQD_OPEN,
-	SD,
-	diskdstate->id,
-	sio,
-	strlen(buf) + 1,
-	sio->mode,
-	shm_offset);
+    char *buf = (char *)IO->shm.get(&shm_offset);
+    xstrncpy(buf, path_, SHMBUF_BLKSZ);
+    int x = storeDiskdSend(_MQD_CREATE,
+			   IO,
+			   id,
+			   this,
+			   strlen(buf) + 1,
+			   mode,
+			   shm_offset);
     if (x < 0) {
-	debug(79, 1) ("storeDiskdSend OPEN: %s\n", xstrerror());
-	storeDiskdShmPut(SD, shm_offset);
-	cbdataReferenceDone(sio->callback_data);
-	cbdataFree(sio);
-	return NULL;
+	errorOccured = true;
+	IO->shm.put (shm_offset);
+	debug(79, 1) ("storeDiskdSend CREATE: %s\n", xstrerror());
+	notifyClient();
+	ioRequestor = NULL;
+	return;
     }
-    commonUfsDirReplAdd(SD, e);
     diskd_stats.create.ops++;
-    return sio;
 }
 
+void
+DiskdFile::read(char *buf, off_t offset, size_t size)
+{
+    assert (ioRequestor.getRaw() != NULL);
+    off_t shm_offset;
+    char *rbuf = (char *)IO->shm.get(&shm_offset);
+    assert(rbuf);
+    int x = storeDiskdSend(_MQD_READ,
+	IO,
+        id,
+	this,
+	(int) size,
+	(int) offset,
+	shm_offset);
+    if (x < 0) {
+	errorOccured = true;
+	IO->shm.put (shm_offset);
+	debug(79, 1) ("storeDiskdSend READ: %s\n", xstrerror());
+	notifyClient();
+	ioRequestor = NULL;
+	return;
+    }
+    diskd_stats.read.ops++;
+}
 
 void
-storeDiskdClose(SwapDir * SD, storeIOState * sio)
+DiskdFile::close()
 {
-    int x;
-    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
-    debug(79, 3) ("storeDiskdClose: dirno %d, fileno %08X\n", SD->index,
-	sio->swap_filen);
-    x = storeDiskdSend(_MQD_CLOSE,
-	SD,
-	diskdstate->id,
-	sio,
+    debug (79,0)("DiskdFile::close: %p closing for %p\n", this, ioRequestor.getRaw());
+    assert (ioRequestor.getRaw());
+    int x = storeDiskdSend(_MQD_CLOSE,
+	IO,
+	id,
+	this,
 	0,
 	0,
 	-1);
     if (x < 0) {
+	errorOccured = true;
 	debug(79, 1) ("storeDiskdSend CLOSE: %s\n", xstrerror());
-	storeDiskdIOCallback(sio, DISK_ERROR);
+	notifyClient();
+	ioRequestor = NULL;
+	return;
     }
-    diskdstate->flags.close_request = 1;
     diskd_stats.close.ops++;
 }
 
+bool
+DiskdFile::error() const
+{
+    return errorOccured;
+}
+
+bool
+DiskdFile::canRead() const
+{
+    return !error();
+}
+
+bool
+DiskdFile::canNotifyClient() const
+{
+    if (!ioRequestor.getRaw()) {
+	debug (79,3)("DiskdFile::canNotifyClient: No ioRequestor to notify\n");
+	return false;
+    }
+    return true;
+}
+
 void
-storeDiskdRead(SwapDir * SD, storeIOState * sio, char *buf, size_t size, off_t offset, STRCB * callback, void *callback_data)
+DiskdFile::notifyClient()
 {
-    int x;
-    off_t shm_offset;
-    char *rbuf;
-    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
-    debug(79, 3) ("storeDiskdRead: dirno %d, fileno %08X\n", sio->swap_dirn, sio->swap_filen);
-    assert(!diskdstate->flags.close_request);
-    if (!cbdataReferenceValid(sio))
-	return;
-    if (diskdstate->flags.reading) {
-	debug(79, 1) ("storeDiskdRead: already reading!\n");
+    if (!canNotifyClient()) {
 	return;
     }
-    assert(sio->read.callback == NULL);
-    assert(sio->read.callback_data == NULL);
-    sio->read.callback = callback;
-    sio->read.callback_data = cbdataReference(callback_data);
-    diskdstate->read_buf = buf;	/* the one passed from above */
-    sio->offset = offset;
-    diskdstate->flags.reading = 1;
-    rbuf = (char *)storeDiskdShmGet(SD, &shm_offset);
-    assert(rbuf);
-    x = storeDiskdSend(_MQD_READ,
-	SD,
-	diskdstate->id,
-	sio,
-	(int) size,
-	(int) offset,
-	shm_offset);
-    if (x < 0) {
-	debug(79, 1) ("storeDiskdSend READ: %s\n", xstrerror());
-	storeDiskdShmPut(SD, shm_offset);
-	storeDiskdIOCallback(sio, DISK_ERROR);
+    ioRequestor->ioCompletedNotification();
+}
+
+void
+DiskdFile::completed(diomsg *M)
+{
+    assert (M->newstyle);
+    switch (M->mtype) {
+	case _MQD_OPEN:
+	    openDone(M);
+	    break;
+	case _MQD_CREATE:
+	    createDone(M);
+	    break;
+	case _MQD_CLOSE:
+	    closeDone(M);
+	    break;
+	case _MQD_READ:
+	    readDone(M);
+	    break;
+	case _MQD_WRITE:
+	    writeDone(M);
+	    break;
+	case _MQD_UNLINK:
+	    assert (0);
+	    break;
+	default:
+	    assert(0);
+	    break;
+	}
+}
+
+void
+DiskdFile::openDone(diomsg *M) {
+    statCounter.syscalls.disk.opens++;
+    debug(79, 3) ("storeDiskdOpenDone: status %d\n", M->status);
+    assert (FILE_MODE(mode) == O_RDONLY);
+    if (M->status < 0) {
+	diskd_stats.open.fail++;
+	errorOccured = true;
+    } else {
+	diskd_stats.open.success++;
     }
-    diskd_stats.read.ops++;
+    notifyClient();
 }
 
 void
-storeDiskdWrite(SwapDir * SD, storeIOState * sio, char *buf, size_t size, off_t offset, FREE * free_func)
+DiskdFile::createDone(diomsg *M) {
+    statCounter.syscalls.disk.opens++;
+    debug(79, 3) ("storeDiskdCreateDone: status %d\n", M->status);
+    if (M->status < 0) {
+	diskd_stats.create.fail++;
+	errorOccured = true;
+    } else {
+	diskd_stats.create.success++;
+    }
+    notifyClient();
+}
+
+CBDATA_CLASS_INIT(diskdstate_t);
+
+void *
+diskdstate_t::operator new (size_t)
 {
-    int x;
-    char *sbuf;
-    off_t shm_offset;
-    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
-    debug(79, 3) ("storeDiskdWrite: dirno %d, fileno %08X\n", SD->index, sio->swap_filen);
-    assert(!diskdstate->flags.close_request);
-    if (!cbdataReferenceValid(sio)) {
-	free_func(buf);
+    CBDATA_INIT_TYPE(diskdstate_t);
+    diskdstate_t *result = cbdataAlloc(diskdstate_t);
+    /* Mark result as being owned - we want the refcounter to do the delete
+     * call */
+    cbdataReference(result);
+    debug (0,0)("diskdstate with base %p allocating\n", result);
+    return result;
+}
+
+void
+diskdstate_t::operator delete (void *address)
+{
+    debug (0,0)("diskdstate with base %p deleting\n",address);
+    diskdstate_t *t = static_cast<diskdstate_t *>(address);
+    cbdataFree(address);
+    /* And allow the memory to be freed */
+    cbdataReferenceDone (t);
+}
+
+diskdstate_t::diskdstate_t(SwapDir *SD, StoreEntry *e_, STIOCB * callback_, void *callback_data_)
+{
+    swap_filen = e_->swap_filen;
+    swap_dirn = SD->index;
+    mode = O_BINARY;
+    callback = callback_;
+    callback_data = cbdataReference(callback_data_);
+    e = e_;
+}
+
+/*
+ * We can't pass memFree() as a free function here, because we need to free
+ * the fsdata variable ..
+ */
+diskdstate_t::~diskdstate_t()
+{
+}
+
+void
+diskdstate_t::ioCompletedNotification()
+{
+    if (opening) {
+	opening = false;
+	debug(79, 3) ("storeDiskdOpenDone: dirno %d, fileno %08x status %d\n",
+		      swap_dirn, swap_filen, theFile->error());
+	assert (FILE_MODE(mode) == O_RDONLY);
+	if (theFile->error()) {
+	    doCallback(DISK_ERROR);
+	}
 	return;
     }
-    diskdstate->flags.writing = 1;
-    sbuf = (char *)storeDiskdShmGet(SD, &shm_offset);
+    if (creating) {
+	creating = false;
+	debug(79, 3) ("storeDiskdCreateDone: dirno %d, fileno %08x status %d\n",
+		      swap_dirn, swap_filen, theFile->error());
+	if (theFile->error()) {
+	    doCallback(DISK_ERROR);
+	}
+	return;
+    }
+    assert (!closing);
+    debug(79, 3) ("diskd::ioCompleted: dirno %d, fileno %08x status %d\n",                      swap_dirn, swap_filen, theFile->error());
+    /* Ok, notification past open means an error has occured */
+    assert (theFile->error());
+    doCallback(DISK_ERROR);
+}
+
+void
+diskdstate_t::closeCompleted()
+{
+    assert (closing);
+    debug(79, 3) ("storeDiskdCloseDone: dirno %d, fileno %08x status %d\n",
+	swap_dirn, swap_filen, theFile->error());
+    if (theFile->error()) {
+	doCallback(DISK_ERROR);
+    } else {
+	doCallback(DISK_OK);
+    }
+}
+ 
+void
+diskdstate_t::close()
+{
+    debug(79, 3) ("storeDiskdClose: dirno %d, fileno %08X\n", swap_dirn,
+	swap_filen);
+    closing = true;
+    ((DiskdFile *)theFile.getRaw())->close();
+}
+
+void
+DiskdFile::write(char const *buf, size_t size, off_t offset, FREE *free_func)
+{
+    off_t shm_offset;
+    char *sbuf = (char *)IO->shm.get(&shm_offset);
     xmemcpy(sbuf, buf, size);
     if (free_func)
-	free_func(buf);
-    x = storeDiskdSend(_MQD_WRITE,
-	SD,
-	diskdstate->id,
-	sio,
+	free_func(const_cast<char *>(buf));
+    int x = storeDiskdSend(_MQD_WRITE,
+	IO,
+        id,
+	this,
 	(int) size,
 	(int) offset,
 	shm_offset);
     if (x < 0) {
+	errorOccured = true;
 	debug(79, 1) ("storeDiskdSend WRITE: %s\n", xstrerror());
-	storeDiskdShmPut(SD, shm_offset);
-	storeDiskdIOCallback(sio, DISK_ERROR);
+	IO->shm.put (shm_offset);
+	notifyClient();
+	ioRequestor = NULL;
+	return;
     }
     diskd_stats.write.ops++;
 }
-
+  
 void
-storeDiskdUnlink(SwapDir * SD, StoreEntry * e)
+DiskdSwapDir::unlink(StoreEntry & e)
 {
     int x;
     off_t shm_offset;
     char *buf;
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)SD->fsdata;
 
-    debug(79, 3) ("storeDiskdUnlink: dirno %d, fileno %08X\n", SD->index,
-	e->swap_filen);
-    commonUfsDirReplRemove(e);
-    commonUfsDirMapBitReset(SD, e->swap_filen);
-    if (diskdinfo->away >= diskdinfo->magic1) {
+    debug(79, 3) ("storeDiskdUnlink: dirno %d, fileno %08X\n", index,
+	e.swap_filen);
+    replacementRemove(&e);
+    mapBitReset(e.swap_filen);
+    if (IO->shedLoad()) {
 	/* Damn, we need to issue a sync unlink here :( */
 	debug(79, 2) ("storeDiskUnlink: Out of queue space, sync unlink\n");
-	commonUfsDirUnlinkFile(SD, e->swap_filen);
+        UFSSwapDir::unlinkFile(e.swap_filen);
 	return;
     }
     /* We can attempt a diskd unlink */
-    buf = (char *)storeDiskdShmGet(SD, &shm_offset);
-    xstrncpy(buf, commonUfsDirFullPath(SD, e->swap_filen, NULL), SHMBUF_BLKSZ);
+    buf = (char *)((DiskdIO *)IO)->shm.get(&shm_offset);
+    xstrncpy(buf, fullPath(e.swap_filen, NULL), SHMBUF_BLKSZ);
     x = storeDiskdSend(_MQD_UNLINK,
-	SD,
-	e->swap_filen,
-	NULL,
+	(DiskdIO *)IO,
+	e.swap_filen,
+	(StoreIOState::Pointer )NULL,
 	0,
 	0,
 	shm_offset);
     if (x < 0) {
 	debug(79, 1) ("storeDiskdSend UNLINK: %s\n", xstrerror());
-	unlink(buf);		/* XXX EWW! */
-	storeDiskdShmPut(SD, shm_offset);
+	::unlink(buf);		/* XXX EWW! */
+	((DiskdIO *)IO)->shm.put (shm_offset);
     }
     diskd_stats.unlink.ops++;
 }
 
 
 /*  === STATIC =========================================================== */
 
-static void
-storeDiskdOpenDone(diomsg * M)
-{
-    storeIOState *sio = (storeIOState *)M->callback_data;
-    statCounter.syscalls.disk.opens++;
-    debug(79, 3) ("storeDiskdOpenDone: dirno %d, fileno %08x status %d\n",
-	sio->swap_dirn, sio->swap_filen, M->status);
-    if (M->status < 0) {
-	FILE_MODE(sio->mode) == O_RDONLY ? diskd_stats.open.fail++ : diskd_stats.create.fail++;
-	storeDiskdIOCallback(sio, DISK_ERROR);
-    } else {
-	FILE_MODE(sio->mode) == O_RDONLY ? diskd_stats.open.success++ : diskd_stats.create.success++;
-    }
-}
-
-static void
-storeDiskdCloseDone(diomsg * M)
+void
+DiskdFile::closeDone(diomsg * M)
 {
-    storeIOState *sio = (storeIOState *)M->callback_data;
     statCounter.syscalls.disk.closes++;
-    debug(79, 3) ("storeDiskdCloseDone: dirno %d, fileno %08x status %d\n",
-	sio->swap_dirn, sio->swap_filen, M->status);
+    debug(79, 3) ("storeDiskdCloseDone: status %d\n", M->status);
     if (M->status < 0) {
 	diskd_stats.close.fail++;
-	storeDiskdIOCallback(sio, DISK_ERROR);
-	return;
+	errorOccured = true;
+    } else {
+	diskd_stats.close.success++;
     }
-    diskd_stats.close.success++;
-    storeDiskdIOCallback(sio, DISK_OK);
+    if (canNotifyClient())
+	ioRequestor->closeCompleted();
+    ioRequestor = NULL;
 }
 
-static void
-storeDiskdReadDone(diomsg * M)
+void
+DiskdFile::readDone(diomsg * M)
 {
-    storeIOState *sio = (storeIOState *)M->callback_data;
-    STRCB *callback = sio->read.callback;
-    void *cbdata;
-    SwapDir *sd = INDEXSD(sio->swap_dirn);
-    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
-    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
-    char *their_buf = diskdstate->read_buf;
-    char *sbuf;
-    size_t len;
     statCounter.syscalls.disk.reads++;
-    diskdstate->flags.reading = 0;
-    debug(79, 3) ("storeDiskdReadDone: dirno %d, fileno %08x status %d\n",
-	sio->swap_dirn, sio->swap_filen, M->status);
+    debug(79, 3) ("DiskdFile::readDone: status %d\n", M->status);
+
     if (M->status < 0) {
 	diskd_stats.read.fail++;
-	storeDiskdIOCallback(sio, DISK_ERROR);
+	errorOccured = true;
+	ioRequestor->readCompleted(NULL, -1, DISK_ERROR);
 	return;
     }
     diskd_stats.read.success++;
-    sbuf = diskdinfo->shm.buf + M->shm_offset;
-    len = M->status;
-    sio->offset += len;
+
+    ioRequestor->readCompleted (IO->shm.buf + M->shm_offset,  M->status, DISK_OK);
+}
+
+void
+diskdstate_t::readCompleted(const char *buf, int len, int errflag)
+{
+    reading = false;
+    debug(79, 3) ("storeDiskdReadDone: dirno %d, fileno %08x len %d\n",
+	swap_dirn, swap_filen, len);
+    if (len > 0)
+	offset_ += len;
+
+    STRCB *callback = read.callback;
     assert(callback);
-    sio->read.callback = NULL;
-    if (cbdataReferenceValidDone(sio->read.callback_data, &cbdata)) {
-	assert(!diskdstate->flags.close_request);
+    read.callback = NULL;
+    void *cbdata;
+    if (cbdataReferenceValidDone(read.callback_data, &cbdata)) {
+	assert (!closing);
 	/*
 	 * Only copy the data if the callback is still valid,
 	 * if it isn't valid then the request should have been
 	 * aborted.
 	 *   -- adrian
 	 */
-	xmemcpy(their_buf, sbuf, len);	/* yucky copy */
-	callback(cbdata, their_buf, len);
+	if (len > 0 && read_buf != buf)
+	    memcpy(read_buf, buf, len);
+	callback(cbdata, read_buf, len);
     }
 }
 
-static void
-storeDiskdWriteDone(diomsg * M)
+void
+diskdstate_t::writeCompleted(int errflag, size_t len)
 {
-    storeIOState *sio = (storeIOState *)M->callback_data;
-    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
-    statCounter.syscalls.disk.writes++;
-    diskdstate->flags.writing = 0;
+    writing = false;
     debug(79, 3) ("storeDiskdWriteDone: dirno %d, fileno %08x status %d\n",
-	sio->swap_dirn, sio->swap_filen, M->status);
+	swap_dirn, swap_filen, len);
+    offset_ += len;
+    if (errflag)
+	doCallback(DISK_ERROR);
+}
+
+void
+DiskdFile::writeDone(diomsg *M)
+{
+    statCounter.syscalls.disk.writes++;
+    debug(79, 3) ("storeDiskdWriteDone: status %d\n", M->status);
     if (M->status < 0) {
+	errorOccured = true;
 	diskd_stats.write.fail++;
-	storeDiskdIOCallback(sio, DISK_ERROR);
+	ioRequestor->writeCompleted (DISK_ERROR,0);
 	return;
     }
     diskd_stats.write.success++;
-    sio->offset += M->status;
+    ioRequestor->writeCompleted (DISK_OK,M->status);
 }
 
 static void
