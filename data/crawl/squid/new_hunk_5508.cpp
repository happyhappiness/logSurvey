static int commRetryConnect(ConnectStateData * cs);
CBDATA_TYPE(ConnectStateData);


struct _fdc_t {
	int active;
	dlink_list CommCallbackList;
	struct {
		char *buf;
		int size;
		IOCB *handler;
		void *handler_data;
	} read;
	struct {
		struct sockaddr_in me;
		struct sockaddr_in pn;
		IOACB *handler;
		void *handler_data;
	} accept;
	struct CommFiller {
		StoreIOBuffer requestedData;
		size_t amountDone;
		IOFCB *handler;
		void *handler_data;
	} fill;

};
typedef struct _fdc_t fdc_t;

typedef enum {
	COMM_CB_READ = 1,
	COMM_CB_WRITE,
	COMM_CB_ACCEPT,
	COMM_CB_FILL
} comm_callback_t;

struct _CommCallbackData {
	comm_callback_t type;
	dlink_node fd_node;
	dlink_node h_node;
	int fd;
	int newfd;	/* for accept() */
	char *buf;
	int retval;
	union {
	    IOCB *r_callback;
	    IOACB *a_callback;
	    IOFCB *f_callback;
	} c;
	void *callback_data;
	comm_err_t errcode;
	int xerrno;
	int seqnum;
	struct sockaddr_in me;
	struct sockaddr_in pn;
	StoreIOBuffer sb;
};
typedef struct _CommCallbackData CommCallbackData;

struct _fd_debug_t {
  char *close_file;
  int close_line;
};
typedef struct _fd_debug_t fd_debug_t;

static MemPool *comm_write_pool = NULL;
static MemPool *conn_close_pool = NULL;
static MemPool *comm_callback_pool = NULL;
fdc_t *fdc_table = NULL;
fd_debug_t *fdd_table = NULL;
dlink_list CommCallbackList;
static int CommCallbackSeqnum = 1;


/* New and improved stuff */

/*
 * return whether there are entries in the callback queue
 */
int
comm_existsiocallback(void)
{
	return CommCallbackList.head == NULL;
}

/*
 * add an IO callback
 *
 * IO callbacks are added when we want to notify someone that some IO
 * has finished but we don't want to risk re-entering a non-reentrant
 * code block.
 */
static void
comm_addreadcallback(int fd, IOCB *callback, char *buf, size_t retval, comm_err_t errcode,
  int xerrno, void *callback_data)
{
	CommCallbackData *cio;

	assert(fdc_table[fd].active == 1);

	/* Allocate a new struct */
	cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);

	/* Throw our data into it */
	cio->fd = fd;
	cio->retval = retval;
	cio->xerrno = xerrno;
	cio->errcode = errcode;
	cio->c.r_callback = callback;
	cio->callback_data = callback_data;
	cio->seqnum = CommCallbackSeqnum;
        cio->buf = buf;
	cio->type = COMM_CB_READ;

	/* Add it to the end of the list */
	dlinkAddTail(cio, &(cio->h_node), &CommCallbackList);

	/* and add it to the end of the fd list */
	dlinkAddTail(cio, &(cio->fd_node), &(fdc_table[fd].CommCallbackList));

}


static void
comm_addacceptcallback(int fd, int newfd, IOACB *callback, struct sockaddr_in *pn,
  struct sockaddr_in *me, comm_err_t errcode, int xerrno, void *callback_data)
{
	CommCallbackData *cio;

	assert(fdc_table[fd].active == 1);

	/* Allocate a new struct */
	cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);

	/* Throw our data into it */
	cio->fd = fd;
	cio->xerrno = xerrno;
	cio->errcode = errcode;
	cio->c.a_callback = callback;
	cio->callback_data = callback_data;
	cio->seqnum = CommCallbackSeqnum;
	cio->type = COMM_CB_ACCEPT;
	cio->newfd = newfd;
	cio->pn = *pn;
	cio->me = *me;

	/* Add it to the end of the list */
	dlinkAddTail(cio, &(cio->h_node), &CommCallbackList);

	/* and add it to the end of the fd list */
	dlinkAddTail(cio, &(cio->fd_node), &(fdc_table[fd].CommCallbackList));

}

static void
comm_add_fill_callback(int fd, size_t retval, comm_err_t errcode, int xerrno)
{
	CommCallbackData *cio;

	assert(fdc_table[fd].active == 1);

	/* Allocate a new struct */
	cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);

	/* Throw our data into it */
	cio->fd = fd;
	cio->xerrno = xerrno;
	cio->errcode = errcode;
	cio->c.f_callback = fdc_table[fd].fill.handler;
	cio->callback_data = fdc_table[fd].fill.handler_data;
	cio->seqnum = CommCallbackSeqnum;
	cio->type = COMM_CB_FILL;
	/* retval not used */
	cio->retval = -1;
	cio->sb = fdc_table[fd].fill.requestedData;
	cio->sb.length = retval;
	/* Clear out fd state */
	fdc_table[fd].fill.handler = NULL;
	fdc_table[fd].fill.handler_data = NULL;

	/* Add it to the end of the list */
	dlinkAddTail(cio, &(cio->h_node), &CommCallbackList);

	/* and add it to the end of the fd list */
	dlinkAddTail(cio, &(cio->fd_node), &(fdc_table[fd].CommCallbackList));
}




static void
comm_call_io_callback(CommCallbackData *cio)
{
		switch(cio->type) {
		    case COMM_CB_READ:
		        cio->c.r_callback(cio->fd, cio->buf, cio->retval, cio->errcode, cio->xerrno,
		          cio->callback_data);
			break;
		    case COMM_CB_WRITE:
			fatal("write comm hasn't been implemented yet!");
		        break;
		    case COMM_CB_ACCEPT:
                        cio->c.a_callback(cio->fd, cio->newfd, &cio->me, &cio->pn, cio->errcode,
			  cio->xerrno, cio->callback_data);
			break;
		    case COMM_CB_FILL:
			cio->c.f_callback(cio->fd, cio->sb, cio->errcode,
			  cio->xerrno, cio->callback_data);
                        break;
		    default:
			fatal("unknown comm io callback type!");
			break;
		};
}


/*
 * call the IO callbacks
 *
 * This should be called before comm_select() so code can attempt to
 * initiate some IO.
 *
 * When io callbacks are added, they are added with the current
 * sequence number. The sequence number is incremented in this routine -
 * since callbacks are added to the _tail_ of the list, when we hit a
 * callback with a seqnum _not_ what it was when we entered this routine,    
 * we can stop.
 */
void
comm_calliocallback(void)
{
	CommCallbackData *cio;
	dlink_node *node;
	int oldseqnum = CommCallbackSeqnum;

	/* Call our callbacks until we hit NULL or the seqnum changes */
	while (CommCallbackList.head != NULL) {
		node = (dlink_node *)CommCallbackList.head;
		cio = (CommCallbackData *)node->data;

		/* If seqnum isn't the same, its time to die */
		if (cio->seqnum != oldseqnum)
			break;		/* we've hit newly-added events */

		assert(fdc_table[cio->fd].active == 1);

		dlinkDelete(&cio->h_node, &CommCallbackList);
		dlinkDelete(&cio->fd_node, &(fdc_table[cio->fd].CommCallbackList));
		comm_call_io_callback(cio);
		memPoolFree(comm_callback_pool, cio);
	}
}


/*
 * Queue a callback
 */
static void
comm_read_callback(int fd, int retval, comm_err_t errcode, int xerrno)
{
	fdc_t *Fc = &fdc_table[fd];

	assert(Fc->read.handler != NULL);

	comm_addreadcallback(fd, Fc->read.handler, Fc->read.buf, retval, errcode, xerrno,
	    Fc->read.handler_data);
	Fc->read.handler = NULL;
	Fc->read.handler_data = NULL;
}

/*
 * Attempt a read
 *
 * If the read attempt succeeds or fails, call the callback.
 * Else, wait for another IO notification.
 */
static void
comm_read_try(int fd, void *data)
{
	fdc_t *Fc = &fdc_table[fd];
	int retval;

	/* make sure we actually have a callback */
	assert(Fc->read.handler != NULL);

	/* Attempt a read */
        statCounter.syscalls.sock.reads++;
	retval = FD_READ_METHOD(fd, Fc->read.buf, Fc->read.size);
	if (retval < 0 && !ignoreErrno(errno)) {
		comm_read_callback(fd, -1, COMM_ERROR, errno);
		return;
	};

	/* See if we read anything */
	/* Note - read 0 == socket EOF, which is a valid read */
	if (retval >= 0) {
                fd_bytes(fd, retval, FD_READ);
		comm_read_callback(fd, retval, COMM_OK, 0);
		return;
	}

	/* Nope, register for some more IO */
        commSetSelect(fd, COMM_SELECT_READ, comm_read_try, NULL, 0);
}

/*
 * Queue a read. handler/handler_data are called when the read
 * completes, on error, or on file descriptor close.
 */
void
comm_read(int fd, char *buf, int size, IOCB *handler, void *handler_data)
{
	/* Make sure we're not reading anything and we're not closing */
	assert(fdc_table[fd].active == 1);
	assert(fdc_table[fd].read.handler == NULL);
        assert(!fd_table[fd].flags.closing);

	/* Queue a read */
	fdc_table[fd].read.buf = buf;
	fdc_table[fd].read.size = size;
	fdc_table[fd].read.handler = handler;
	fdc_table[fd].read.handler_data = handler_data;

#if OPTIMISTIC_IO
        comm_read_try(fd, NULL);
#else
	/* Register intrest in a FD read */
        commSetSelect(fd, COMM_SELECT_READ, comm_read_try, NULL, 0);
#endif
}

static void
comm_fill_read(int fd, char *buf, size_t len, comm_err_t flag, int xerrno, void *data)
{
    /* TODO use a reference to the table entry, or use C++ :] */
    StoreIOBuffer *sb;
    _fdc_t::CommFiller *fill;
    assert(fdc_table[fd].active == 1);

    if (flag != COMM_OK) {
        /* Error! */
	/* XXX This was -1 below, but -1 can't be used for size_t parameters.
	 * The callback should set -1 to the client if needed based on the flags
	 */
	comm_add_fill_callback(fd, 0, flag, xerrno);
	return;
    }
    /* flag is COMM_OK */
    /* We handle EOFs as read lengths of 0! Its eww, but its consistent */
    fill = &fdc_table[fd].fill;
    fill->amountDone += len;
    sb = &fdc_table[fd].fill.requestedData;
    assert(fill->amountDone <= sb->length);
    comm_add_fill_callback(fd, fill->amountDone, COMM_OK, 0);
}

/*
 * Try filling a StoreIOBuffer with some data, and call a callback when successful
 */
void
comm_fill_immediate(int fd, StoreIOBuffer sb, IOFCB *callback, void *data)
{
    assert(fdc_table[fd].fill.handler == NULL);
    /* prevent confusion */
    assert (sb.offset == 0);

    /* If we don't have any data, record details and schedule a read */
    fdc_table[fd].fill.handler = callback;
    fdc_table[fd].fill.handler_data = data;
    fdc_table[fd].fill.requestedData = sb;
    fdc_table[fd].fill.amountDone = 0;

    comm_read(fd, sb.data, sb.length, comm_fill_read, NULL);
}


/*
 * Empty the read buffers
 *
 * This is a magical routine that empties the read buffers.
 * Under some platforms (Linux) if a buffer has data in it before
 * you call close(), the socket will hang and take quite a while
 * to timeout.
 */
static void
comm_empty_os_read_buffers(int fd)
{
#ifdef _SQUID_LINUX_
    /* prevent those nasty RST packets */
    char buf[SQUID_TCP_SO_RCVBUF];
    if (fd_table[fd].flags.nonblocking == 1)
    	while (FD_READ_METHOD(fd, buf, SQUID_TCP_SO_RCVBUF) > 0);
#endif
}


/*
 * Return whether a file descriptor has any pending read request callbacks
 *
 * Assumptions: the fd is open (ie, its not closing)
 */
int
comm_has_pending_read_callback(int fd)
{
    dlink_node *node;
    CommCallbackData *cd;

    assert(fd_table[fd].flags.open == 1);
    assert(fdc_table[fd].active == 1);

    /*
     * XXX I don't like having to walk the list!
     * Instead, if this routine is called often enough, we should
     * also maintain a linked list of _read_ events - we can just
     * check if the list head a HEAD..
     * - adrian
     */
    node = fdc_table[fd].CommCallbackList.head;
    while (node != NULL) {
	cd = (CommCallbackData *)node->data;
	if (cd->type == COMM_CB_READ)
	    return 1;
	node = node->next;
    }

    /* Not found */
    return 0;
}

/*
 * return whether a file descriptor has a read handler
 *
 * Assumptions: the fd is open
 */
int
comm_has_pending_read(int fd)
{
	assert(fd_table[fd].flags.open == 1);
	assert(fdc_table[fd].active == 1);

	return (fdc_table[fd].read.handler != NULL);
}

/*
 * Cancel a pending read. Assert that we have the right parameters,
 * and that there are no pending read events!
 */
void
comm_read_cancel(int fd, IOCB *callback, void *data)
{
    assert(fd_table[fd].flags.open == 1);
    assert(fdc_table[fd].active == 1);

    assert(fdc_table[fd].read.handler == callback);
    assert(fdc_table[fd].read.handler_data == data);

    assert(!comm_has_pending_read_callback(fd));

    /* Ok, we can be reasonably sure we won't lose any data here! */

    /* Delete the callback */
    fdc_table[fd].read.handler = NULL;
    fdc_table[fd].read.handler_data = NULL;
}


void
fdc_open(int fd, unsigned int type, char *desc)
{
	assert(fdc_table[fd].active == 0);

	fdc_table[fd].active = 1;
	fd_open(fd, type, desc);
}


/* Older stuff */

static void
CommWriteStateCallbackAndFree(int fd, comm_err_t code)
