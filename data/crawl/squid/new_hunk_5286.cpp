
static MemPool *comm_write_pool = NULL;
static MemPool *conn_close_pool = NULL;
fdc_t *fdc_table = NULL;
fd_debug_t *fdd_table = NULL;
dlink_list CommCallbackList;


/* New and improved stuff */

MemPool *CommCallbackData::Pool(NULL);
void *
CommCallbackData::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (CommCallbackData));

    if (!Pool)
        Pool = memPoolCreate("CommCallbackData", sizeof (CommCallbackData));

    return memPoolAlloc(Pool);
}

void
CommCallbackData::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
CommCallbackData::deleteSelf() const
{
    delete this;
}

MemPool *CommReadCallbackData::Pool(NULL);
void *
CommReadCallbackData::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (CommReadCallbackData));

    if (!Pool)
        Pool = memPoolCreate("CommReadCallbackData", sizeof (CommReadCallbackData));

    return memPoolAlloc(Pool);
}

void
CommReadCallbackData::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
CommReadCallbackData::deleteSelf() const
{
    delete this;
}

MemPool *CommAcceptCallbackData::Pool(NULL);
void *
CommAcceptCallbackData::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (CommAcceptCallbackData));

    if (!Pool)
        Pool = memPoolCreate("CommAcceptCallbackData", sizeof (CommAcceptCallbackData));

    return memPoolAlloc(Pool);
}

void
CommAcceptCallbackData::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
CommAcceptCallbackData::deleteSelf() const
{
    delete this;
}

MemPool *CommFillCallbackData::Pool(NULL);
void *
CommFillCallbackData::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (CommFillCallbackData));

    if (!Pool)
        Pool = memPoolCreate("CommFillCallbackData", sizeof (CommFillCallbackData));

    return memPoolAlloc(Pool);
}

void
CommFillCallbackData::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
CommFillCallbackData::deleteSelf() const
{
    delete this;
}


MemPool *CommWriteCallbackData::Pool(NULL);
void *
CommWriteCallbackData::operator new (size_t byteCount)
{
    /* derived classes with different sizes must implement their own new */
    assert (byteCount == sizeof (CommWriteCallbackData));

    if (!Pool)
        Pool = memPoolCreate("CommWriteCallbackData", sizeof (CommWriteCallbackData));

    return memPoolAlloc(Pool);
}

void
CommWriteCallbackData::operator delete (void *address)
{
    memPoolFree (Pool, address);
}

void
CommWriteCallbackData::deleteSelf() const
{
    delete this;
}

CommCallbackData::CommCallbackData(CommCommonCallback const &newResults) : result (newResults)
{
    assert(fdc_table[result.fd].active == 1);
    registerSelf();
}

CommReadCallbackData::CommReadCallbackData(CommCommonCallback const &aResult, CallBack<IOCB> aCallback, int aRetval) : CommCallbackData(aResult), callback(aCallback), retval(aRetval)
{}

CommAcceptCallbackData::CommAcceptCallbackData(int const anFd, CallBack<IOACB> aCallback, comm_err_t anErrcode, int anErrno, int aNewFD, ConnectionDetail const &newDetails) :CommCallbackData(CommCommonCallback(anFd, anErrcode, anErrno)), callback (aCallback), newfd(aNewFD), details(newDetails)
{}

CommFillCallbackData::CommFillCallbackData(int const anFd, CallBack<IOFCB> aCallback, comm_err_t anErrcode, int anErrno) :CommCallbackData(CommCommonCallback(anFd, anErrcode, anErrno)), callback (aCallback)
{}

CommWriteCallbackData::CommWriteCallbackData(int const anFd, CallBack<IOWCB> aCallback, comm_err_t anErrcode, int anErrno, int aRetval) :CommCallbackData(CommCommonCallback(anFd, anErrcode, anErrno)), callback (aCallback), retval (aRetval)
{}

void
CommCallbackData::registerSelf()
{
    /* Add it to the end of the list */
    dlinkAddTail(this, &h_node, &CommCallbackList);

    /* and add it to the end of the fd list */
    dlinkAddTail(this, &fd_node, &(fdc_table[result.fd].CommCallbackList));
}

void
CommCallbackData::deRegisterSelf()
{
    dlinkDelete(&h_node, &CommCallbackList);
    dlinkDelete(&fd_node, &(fdc_table[result.fd].CommCallbackList));
}

/*
 * add an IO callback
 *
 * IO callbacks are added when we want to notify someone that some IO
 * has finished but we don't want to risk re-entering a non-reentrant
 * code block.
 */
static void
comm_add_fill_callback(int fd, size_t length, comm_err_t errcode, int xerrno)
{
    CommCallbackData *cio;

    cio = new CommFillCallbackData(fd, CallBack<IOFCB>(fdc_table[fd].fill.handler, fdc_table[fd].fill.handler_data), errcode, xerrno);

    /* Throw our data into it */
    cio->sb = fdc_table[fd].fill.requestedData;
    cio->sb.length = length;
    /* Clear out fd state */
    fdc_table[fd].fill.handler = NULL;
    fdc_table[fd].fill.handler_data = NULL;
}

static void
comm_add_write_callback(int fd, size_t retval, comm_err_t errcode, int xerrno)
{
    CommCallbackData *cio;

    cio = new CommWriteCallbackData(fd, CallBack<IOWCB>(fdc_table[fd].write.handler, fdc_table[fd].write.handler_data), errcode, xerrno, retval);

    /* Clear out fd state */
    fdc_table[fd].write.handler = NULL;
    fdc_table[fd].write.handler_data = NULL;
}

void
CommReadCallbackData::callCallback()
{
    callback.handler(result.fd, buf, retval, result.errcode, result.xerrno, callback.data);
}

void
CommAcceptCallbackData::callCallback()
{
    callback.handler(result.fd, newfd, &details, result.errcode, result.xerrno, callback.data);
}

void
CommWriteCallbackData::callCallback()
{
    callback.handler(result.fd, buf, retval, result.errcode, result.xerrno, callback.data);
}

void
CommFillCallbackData::callCallback()
{
    callback.handler(result.fd, sb, result.errcode, result.xerrno, callback.data);
}

void
CommCallbackData::fdClosing()
{
    result.errcode = COMM_ERR_CLOSING;
}

void
CommCallbackData::callACallback()
{
    assert(fdc_table[result.fd].active == 1);
    deRegisterSelf();
    callCallback();
}

/*
 * call the IO callbacks
