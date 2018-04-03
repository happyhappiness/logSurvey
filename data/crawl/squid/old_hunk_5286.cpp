
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
comm_addacceptcallback(int fd, int newfd, IOACB *callback, ConnectionDetail details, comm_err_t errcode, int xerrno, void *callback_data)
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
    cio->details = details;

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
comm_add_write_callback(int fd, size_t retval, comm_err_t errcode, int xerrno)
{
    CommCallbackData *cio;

    assert(fdc_table[fd].active == 1);

    /* Allocate a new struct */
    cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);

    /* Throw our data into it */
    cio->fd = fd;
    cio->xerrno = xerrno;
    cio->errcode = errcode;
    cio->c.w_callback = fdc_table[fd].write.handler;
    cio->callback_data = fdc_table[fd].write.handler_data;
    cio->seqnum = CommCallbackSeqnum;
    cio->type = COMM_CB_WRITE;
    cio->retval = retval;

    /* Clear out fd state */
    fdc_table[fd].write.handler = NULL;
    fdc_table[fd].write.handler_data = NULL;

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
        cio->c.w_callback(cio->fd, cio->buf, cio->retval, cio->errcode, cio->xerrno,
                          cio->callback_data);
        break;

    case COMM_CB_ACCEPT:
        cio->c.a_callback(cio->fd, cio->newfd, &cio->details, cio->errcode,
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
