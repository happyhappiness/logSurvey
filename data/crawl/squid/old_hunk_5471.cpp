#include <sys/shm.h>

#include "store_diskd.h"

static int storeDiskdSend(int, SwapDir *, int, storeIOState *, int, int, off_t);
static void storeDiskdIOCallback(storeIOState * sio, int errflag);
static CBDUNL storeDiskdIOFreeEntry;

CBDATA_TYPE(storeIOState);

/* === PUBLIC =========================================================== */

storeIOState *
storeDiskdOpen(SwapDir * SD, StoreEntry * e, STFNCB * file_callback,
    STIOCB * callback, void *callback_data)
{
    sfileno f = e->swap_filen;
    int x;
    storeIOState *sio;
    char *buf;
    diskdstate_t *diskdstate;
    off_t shm_offset;
    diskdinfo_t *diskdinfo = (diskdinfo_t *)SD->fsdata;
    debug(79, 3) ("storeDiskdOpen: fileno %08X\n", f);
    /*
     * Fail on open() if there are too many requests queued.
     */
    if (diskdinfo->away > diskdinfo->magic1) {
	debug(79, 3) ("storeDiskdOpen: FAILING, too many requests away\n");
	diskd_stats.open_fail_queue_len++;
	return NULL;
    }
    CBDATA_INIT_TYPE_FREECB(storeIOState, storeDiskdIOFreeEntry);
    sio = cbdataAlloc(storeIOState);
    sio->fsstate = diskdstate = (diskdstate_t *)memPoolAlloc(diskd_state_pool);

    sio->swap_filen = f;
    sio->swap_dirn = SD->index;
    sio->mode = O_RDONLY | O_BINARY;
    sio->callback = callback;
    sio->callback_data = cbdataReference(callback_data);
    sio->e = e;

    diskdstate->flags.writing = 0;
    diskdstate->flags.reading = 0;
    diskdstate->flags.close_request = 0;
    diskdstate->id = diskd_stats.sio_id++;

    buf = (char *)storeDiskdShmGet(SD, &shm_offset);
    xstrncpy(buf, commonUfsDirFullPath(SD, f, NULL), SHMBUF_BLKSZ);
    x = storeDiskdSend(_MQD_OPEN,
	SD,
	diskdstate->id,
	sio,
	strlen(buf) + 1,
	O_RDONLY,
	shm_offset);
    if (x < 0) {
	debug(79, 1) ("storeDiskdSend OPEN: %s\n", xstrerror());
	storeDiskdShmPut(SD, shm_offset);
	cbdataReferenceDone(sio->callback_data);
	cbdataFree(sio);
	return NULL;
    }
    diskd_stats.open.ops++;
    return sio;
}

storeIOState *
storeDiskdCreate(SwapDir * SD, StoreEntry * e, STFNCB * file_callback,
    STIOCB * callback, void *callback_data)
{
    sfileno f;
    int x;
    storeIOState *sio;
    char *buf;
    off_t shm_offset;
    diskdinfo_t *diskdinfo = (diskdinfo_t *)SD->fsdata;
    diskdstate_t *diskdstate;
    /*
     * Fail on open() if there are too many requests queued.
     */
    if (diskdinfo->away > diskdinfo->magic1) {
	diskd_stats.open_fail_queue_len++;
	return NULL;
    }
    /* Allocate a number */
    f = commonUfsDirMapBitAllocate(SD);
    debug(79, 3) ("storeDiskdCreate: fileno %08X\n", f);

    CBDATA_INIT_TYPE_FREECB(storeIOState, storeDiskdIOFreeEntry);
    sio = cbdataAlloc(storeIOState);
    sio->fsstate = diskdstate = (diskdstate_t *)memPoolAlloc(diskd_state_pool);

    sio->swap_filen = f;
    sio->swap_dirn = SD->index;
    sio->mode = O_WRONLY | O_CREAT | O_TRUNC;
    sio->callback = callback;
    sio->callback_data = cbdataReference(callback_data);
    sio->e = e;

    diskdstate->flags.writing = 0;
    diskdstate->flags.reading = 0;
    diskdstate->flags.close_request = 0;
    diskdstate->id = diskd_stats.sio_id++;

    buf = (char *)storeDiskdShmGet(SD, &shm_offset);
    xstrncpy(buf, commonUfsDirFullPath(SD, f, NULL), SHMBUF_BLKSZ);
    x = storeDiskdSend(_MQD_OPEN,
	SD,
	diskdstate->id,
	sio,
	strlen(buf) + 1,
	sio->mode,
	shm_offset);
    if (x < 0) {
	debug(79, 1) ("storeDiskdSend OPEN: %s\n", xstrerror());
	storeDiskdShmPut(SD, shm_offset);
	cbdataReferenceDone(sio->callback_data);
	cbdataFree(sio);
	return NULL;
    }
    commonUfsDirReplAdd(SD, e);
    diskd_stats.create.ops++;
    return sio;
}


void
storeDiskdClose(SwapDir * SD, storeIOState * sio)
{
    int x;
    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
    debug(79, 3) ("storeDiskdClose: dirno %d, fileno %08X\n", SD->index,
	sio->swap_filen);
    x = storeDiskdSend(_MQD_CLOSE,
	SD,
	diskdstate->id,
	sio,
	0,
	0,
	-1);
    if (x < 0) {
	debug(79, 1) ("storeDiskdSend CLOSE: %s\n", xstrerror());
	storeDiskdIOCallback(sio, DISK_ERROR);
    }
    diskdstate->flags.close_request = 1;
    diskd_stats.close.ops++;
}

void
storeDiskdRead(SwapDir * SD, storeIOState * sio, char *buf, size_t size, off_t offset, STRCB * callback, void *callback_data)
{
    int x;
    off_t shm_offset;
    char *rbuf;
    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
    debug(79, 3) ("storeDiskdRead: dirno %d, fileno %08X\n", sio->swap_dirn, sio->swap_filen);
    assert(!diskdstate->flags.close_request);
    if (!cbdataReferenceValid(sio))
	return;
    if (diskdstate->flags.reading) {
	debug(79, 1) ("storeDiskdRead: already reading!\n");
	return;
    }
    assert(sio->read.callback == NULL);
    assert(sio->read.callback_data == NULL);
    sio->read.callback = callback;
    sio->read.callback_data = cbdataReference(callback_data);
    diskdstate->read_buf = buf;	/* the one passed from above */
    sio->offset = offset;
    diskdstate->flags.reading = 1;
    rbuf = (char *)storeDiskdShmGet(SD, &shm_offset);
    assert(rbuf);
    x = storeDiskdSend(_MQD_READ,
	SD,
	diskdstate->id,
	sio,
	(int) size,
	(int) offset,
	shm_offset);
    if (x < 0) {
	debug(79, 1) ("storeDiskdSend READ: %s\n", xstrerror());
	storeDiskdShmPut(SD, shm_offset);
	storeDiskdIOCallback(sio, DISK_ERROR);
    }
    diskd_stats.read.ops++;
}

void
storeDiskdWrite(SwapDir * SD, storeIOState * sio, char *buf, size_t size, off_t offset, FREE * free_func)
{
    int x;
    char *sbuf;
    off_t shm_offset;
    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
    debug(79, 3) ("storeDiskdWrite: dirno %d, fileno %08X\n", SD->index, sio->swap_filen);
    assert(!diskdstate->flags.close_request);
    if (!cbdataReferenceValid(sio)) {
	free_func(buf);
	return;
    }
    diskdstate->flags.writing = 1;
    sbuf = (char *)storeDiskdShmGet(SD, &shm_offset);
    xmemcpy(sbuf, buf, size);
    if (free_func)
	free_func(buf);
    x = storeDiskdSend(_MQD_WRITE,
	SD,
	diskdstate->id,
	sio,
	(int) size,
	(int) offset,
	shm_offset);
    if (x < 0) {
	debug(79, 1) ("storeDiskdSend WRITE: %s\n", xstrerror());
	storeDiskdShmPut(SD, shm_offset);
	storeDiskdIOCallback(sio, DISK_ERROR);
    }
    diskd_stats.write.ops++;
}

void
storeDiskdUnlink(SwapDir * SD, StoreEntry * e)
{
    int x;
    off_t shm_offset;
    char *buf;
    diskdinfo_t *diskdinfo = (diskdinfo_t *)SD->fsdata;

    debug(79, 3) ("storeDiskdUnlink: dirno %d, fileno %08X\n", SD->index,
	e->swap_filen);
    commonUfsDirReplRemove(e);
    commonUfsDirMapBitReset(SD, e->swap_filen);
    if (diskdinfo->away >= diskdinfo->magic1) {
	/* Damn, we need to issue a sync unlink here :( */
	debug(79, 2) ("storeDiskUnlink: Out of queue space, sync unlink\n");
	commonUfsDirUnlinkFile(SD, e->swap_filen);
	return;
    }
    /* We can attempt a diskd unlink */
    buf = (char *)storeDiskdShmGet(SD, &shm_offset);
    xstrncpy(buf, commonUfsDirFullPath(SD, e->swap_filen, NULL), SHMBUF_BLKSZ);
    x = storeDiskdSend(_MQD_UNLINK,
	SD,
	e->swap_filen,
	NULL,
	0,
	0,
	shm_offset);
    if (x < 0) {
	debug(79, 1) ("storeDiskdSend UNLINK: %s\n", xstrerror());
	unlink(buf);		/* XXX EWW! */
	storeDiskdShmPut(SD, shm_offset);
    }
    diskd_stats.unlink.ops++;
}


/*  === STATIC =========================================================== */

static void
storeDiskdOpenDone(diomsg * M)
{
    storeIOState *sio = (storeIOState *)M->callback_data;
    statCounter.syscalls.disk.opens++;
    debug(79, 3) ("storeDiskdOpenDone: dirno %d, fileno %08x status %d\n",
	sio->swap_dirn, sio->swap_filen, M->status);
    if (M->status < 0) {
	FILE_MODE(sio->mode) == O_RDONLY ? diskd_stats.open.fail++ : diskd_stats.create.fail++;
	storeDiskdIOCallback(sio, DISK_ERROR);
    } else {
	FILE_MODE(sio->mode) == O_RDONLY ? diskd_stats.open.success++ : diskd_stats.create.success++;
    }
}

static void
storeDiskdCloseDone(diomsg * M)
{
    storeIOState *sio = (storeIOState *)M->callback_data;
    statCounter.syscalls.disk.closes++;
    debug(79, 3) ("storeDiskdCloseDone: dirno %d, fileno %08x status %d\n",
	sio->swap_dirn, sio->swap_filen, M->status);
    if (M->status < 0) {
	diskd_stats.close.fail++;
	storeDiskdIOCallback(sio, DISK_ERROR);
	return;
    }
    diskd_stats.close.success++;
    storeDiskdIOCallback(sio, DISK_OK);
}

static void
storeDiskdReadDone(diomsg * M)
{
    storeIOState *sio = (storeIOState *)M->callback_data;
    STRCB *callback = sio->read.callback;
    void *cbdata;
    SwapDir *sd = INDEXSD(sio->swap_dirn);
    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
    diskdinfo_t *diskdinfo = (diskdinfo_t *)sd->fsdata;
    char *their_buf = diskdstate->read_buf;
    char *sbuf;
    size_t len;
    statCounter.syscalls.disk.reads++;
    diskdstate->flags.reading = 0;
    debug(79, 3) ("storeDiskdReadDone: dirno %d, fileno %08x status %d\n",
	sio->swap_dirn, sio->swap_filen, M->status);
    if (M->status < 0) {
	diskd_stats.read.fail++;
	storeDiskdIOCallback(sio, DISK_ERROR);
	return;
    }
    diskd_stats.read.success++;
    sbuf = diskdinfo->shm.buf + M->shm_offset;
    len = M->status;
    sio->offset += len;
    assert(callback);
    sio->read.callback = NULL;
    if (cbdataReferenceValidDone(sio->read.callback_data, &cbdata)) {
	assert(!diskdstate->flags.close_request);
	/*
	 * Only copy the data if the callback is still valid,
	 * if it isn't valid then the request should have been
	 * aborted.
	 *   -- adrian
	 */
	xmemcpy(their_buf, sbuf, len);	/* yucky copy */
	callback(cbdata, their_buf, len);
    }
}

static void
storeDiskdWriteDone(diomsg * M)
{
    storeIOState *sio = (storeIOState *)M->callback_data;
    diskdstate_t *diskdstate = (diskdstate_t *)sio->fsstate;
    statCounter.syscalls.disk.writes++;
    diskdstate->flags.writing = 0;
    debug(79, 3) ("storeDiskdWriteDone: dirno %d, fileno %08x status %d\n",
	sio->swap_dirn, sio->swap_filen, M->status);
    if (M->status < 0) {
	diskd_stats.write.fail++;
	storeDiskdIOCallback(sio, DISK_ERROR);
	return;
    }
    diskd_stats.write.success++;
    sio->offset += M->status;
}

static void
