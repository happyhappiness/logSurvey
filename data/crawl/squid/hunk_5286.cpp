 
 static MemPool *comm_write_pool = NULL;
 static MemPool *conn_close_pool = NULL;
-static MemPool *comm_callback_pool = NULL;
 fdc_t *fdc_table = NULL;
 fd_debug_t *fdd_table = NULL;
 dlink_list CommCallbackList;
-static int CommCallbackSeqnum = 1;
 
 
 /* New and improved stuff */
 
-/*
- * return whether there are entries in the callback queue
- */
-int
-comm_existsiocallback(void)
+MemPool *CommCallbackData::Pool(NULL);
+void *
+CommCallbackData::operator new (size_t byteCount)
 {
-    return CommCallbackList.head == NULL;
+    /* derived classes with different sizes must implement their own new */
+    assert (byteCount == sizeof (CommCallbackData));
+
+    if (!Pool)
+        Pool = memPoolCreate("CommCallbackData", sizeof (CommCallbackData));
+
+    return memPoolAlloc(Pool);
 }
 
-/*
- * add an IO callback
- *
- * IO callbacks are added when we want to notify someone that some IO
- * has finished but we don't want to risk re-entering a non-reentrant
- * code block.
- */
-static void
-comm_addreadcallback(int fd, IOCB *callback, char *buf, size_t retval, comm_err_t errcode,
-                     int xerrno, void *callback_data)
+void
+CommCallbackData::operator delete (void *address)
 {
-    CommCallbackData *cio;
+    memPoolFree (Pool, address);
+}
 
-    assert(fdc_table[fd].active == 1);
+void
+CommCallbackData::deleteSelf() const
+{
+    delete this;
+}
 
-    /* Allocate a new struct */
-    cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);
+MemPool *CommReadCallbackData::Pool(NULL);
+void *
+CommReadCallbackData::operator new (size_t byteCount)
+{
+    /* derived classes with different sizes must implement their own new */
+    assert (byteCount == sizeof (CommReadCallbackData));
 
-    /* Throw our data into it */
-    cio->fd = fd;
-    cio->retval = retval;
-    cio->xerrno = xerrno;
-    cio->errcode = errcode;
-    cio->c.r_callback = callback;
-    cio->callback_data = callback_data;
-    cio->seqnum = CommCallbackSeqnum;
-    cio->buf = buf;
-    cio->type = COMM_CB_READ;
+    if (!Pool)
+        Pool = memPoolCreate("CommReadCallbackData", sizeof (CommReadCallbackData));
 
-    /* Add it to the end of the list */
-    dlinkAddTail(cio, &(cio->h_node), &CommCallbackList);
+    return memPoolAlloc(Pool);
+}
 
-    /* and add it to the end of the fd list */
-    dlinkAddTail(cio, &(cio->fd_node), &(fdc_table[fd].CommCallbackList));
+void
+CommReadCallbackData::operator delete (void *address)
+{
+    memPoolFree (Pool, address);
+}
 
+void
+CommReadCallbackData::deleteSelf() const
+{
+    delete this;
 }
 
+MemPool *CommAcceptCallbackData::Pool(NULL);
+void *
+CommAcceptCallbackData::operator new (size_t byteCount)
+{
+    /* derived classes with different sizes must implement their own new */
+    assert (byteCount == sizeof (CommAcceptCallbackData));
 
+    if (!Pool)
+        Pool = memPoolCreate("CommAcceptCallbackData", sizeof (CommAcceptCallbackData));
 
-static void
-comm_addacceptcallback(int fd, int newfd, IOACB *callback, ConnectionDetail details, comm_err_t errcode, int xerrno, void *callback_data)
+    return memPoolAlloc(Pool);
+}
+
+void
+CommAcceptCallbackData::operator delete (void *address)
 {
-    CommCallbackData *cio;
+    memPoolFree (Pool, address);
+}
 
-    assert(fdc_table[fd].active == 1);
+void
+CommAcceptCallbackData::deleteSelf() const
+{
+    delete this;
+}
 
-    /* Allocate a new struct */
-    cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);
+MemPool *CommFillCallbackData::Pool(NULL);
+void *
+CommFillCallbackData::operator new (size_t byteCount)
+{
+    /* derived classes with different sizes must implement their own new */
+    assert (byteCount == sizeof (CommFillCallbackData));
 
-    /* Throw our data into it */
-    cio->fd = fd;
-    cio->xerrno = xerrno;
-    cio->errcode = errcode;
-    cio->c.a_callback = callback;
-    cio->callback_data = callback_data;
-    cio->seqnum = CommCallbackSeqnum;
-    cio->type = COMM_CB_ACCEPT;
-    cio->newfd = newfd;
-    cio->details = details;
+    if (!Pool)
+        Pool = memPoolCreate("CommFillCallbackData", sizeof (CommFillCallbackData));
+
+    return memPoolAlloc(Pool);
+}
+
+void
+CommFillCallbackData::operator delete (void *address)
+{
+    memPoolFree (Pool, address);
+}
+
+void
+CommFillCallbackData::deleteSelf() const
+{
+    delete this;
+}
+
+
+MemPool *CommWriteCallbackData::Pool(NULL);
+void *
+CommWriteCallbackData::operator new (size_t byteCount)
+{
+    /* derived classes with different sizes must implement their own new */
+    assert (byteCount == sizeof (CommWriteCallbackData));
+
+    if (!Pool)
+        Pool = memPoolCreate("CommWriteCallbackData", sizeof (CommWriteCallbackData));
+
+    return memPoolAlloc(Pool);
+}
+
+void
+CommWriteCallbackData::operator delete (void *address)
+{
+    memPoolFree (Pool, address);
+}
+
+void
+CommWriteCallbackData::deleteSelf() const
+{
+    delete this;
+}
+
+CommCallbackData::CommCallbackData(CommCommonCallback const &newResults) : result (newResults)
+{
+    assert(fdc_table[result.fd].active == 1);
+    registerSelf();
+}
+
+CommReadCallbackData::CommReadCallbackData(CommCommonCallback const &aResult, CallBack<IOCB> aCallback, int aRetval) : CommCallbackData(aResult), callback(aCallback), retval(aRetval)
+{}
+
+CommAcceptCallbackData::CommAcceptCallbackData(int const anFd, CallBack<IOACB> aCallback, comm_err_t anErrcode, int anErrno, int aNewFD, ConnectionDetail const &newDetails) :CommCallbackData(CommCommonCallback(anFd, anErrcode, anErrno)), callback (aCallback), newfd(aNewFD), details(newDetails)
+{}
+
+CommFillCallbackData::CommFillCallbackData(int const anFd, CallBack<IOFCB> aCallback, comm_err_t anErrcode, int anErrno) :CommCallbackData(CommCommonCallback(anFd, anErrcode, anErrno)), callback (aCallback)
+{}
 
+CommWriteCallbackData::CommWriteCallbackData(int const anFd, CallBack<IOWCB> aCallback, comm_err_t anErrcode, int anErrno, int aRetval) :CommCallbackData(CommCommonCallback(anFd, anErrcode, anErrno)), callback (aCallback), retval (aRetval)
+{}
+
+void
+CommCallbackData::registerSelf()
+{
     /* Add it to the end of the list */
-    dlinkAddTail(cio, &(cio->h_node), &CommCallbackList);
+    dlinkAddTail(this, &h_node, &CommCallbackList);
 
     /* and add it to the end of the fd list */
-    dlinkAddTail(cio, &(cio->fd_node), &(fdc_table[fd].CommCallbackList));
+    dlinkAddTail(this, &fd_node, &(fdc_table[result.fd].CommCallbackList));
+}
 
+void
+CommCallbackData::deRegisterSelf()
+{
+    dlinkDelete(&h_node, &CommCallbackList);
+    dlinkDelete(&fd_node, &(fdc_table[result.fd].CommCallbackList));
 }
 
+/*
+ * add an IO callback
+ *
+ * IO callbacks are added when we want to notify someone that some IO
+ * has finished but we don't want to risk re-entering a non-reentrant
+ * code block.
+ */
 static void
-comm_add_fill_callback(int fd, size_t retval, comm_err_t errcode, int xerrno)
+comm_add_fill_callback(int fd, size_t length, comm_err_t errcode, int xerrno)
 {
     CommCallbackData *cio;
 
-    assert(fdc_table[fd].active == 1);
-
-    /* Allocate a new struct */
-    cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);
+    cio = new CommFillCallbackData(fd, CallBack<IOFCB>(fdc_table[fd].fill.handler, fdc_table[fd].fill.handler_data), errcode, xerrno);
 
     /* Throw our data into it */
-    cio->fd = fd;
-    cio->xerrno = xerrno;
-    cio->errcode = errcode;
-    cio->c.f_callback = fdc_table[fd].fill.handler;
-    cio->callback_data = fdc_table[fd].fill.handler_data;
-    cio->seqnum = CommCallbackSeqnum;
-    cio->type = COMM_CB_FILL;
-    /* retval not used */
-    cio->retval = -1;
     cio->sb = fdc_table[fd].fill.requestedData;
-    cio->sb.length = retval;
+    cio->sb.length = length;
     /* Clear out fd state */
     fdc_table[fd].fill.handler = NULL;
     fdc_table[fd].fill.handler_data = NULL;
-
-    /* Add it to the end of the list */
-    dlinkAddTail(cio, &(cio->h_node), &CommCallbackList);
-
-    /* and add it to the end of the fd list */
-    dlinkAddTail(cio, &(cio->fd_node), &(fdc_table[fd].CommCallbackList));
 }
 
 static void
 comm_add_write_callback(int fd, size_t retval, comm_err_t errcode, int xerrno)
 {
     CommCallbackData *cio;
 
-    assert(fdc_table[fd].active == 1);
-
-    /* Allocate a new struct */
-    cio = (CommCallbackData *)memPoolAlloc(comm_callback_pool);
-
-    /* Throw our data into it */
-    cio->fd = fd;
-    cio->xerrno = xerrno;
-    cio->errcode = errcode;
-    cio->c.w_callback = fdc_table[fd].write.handler;
-    cio->callback_data = fdc_table[fd].write.handler_data;
-    cio->seqnum = CommCallbackSeqnum;
-    cio->type = COMM_CB_WRITE;
-    cio->retval = retval;
+    cio = new CommWriteCallbackData(fd, CallBack<IOWCB>(fdc_table[fd].write.handler, fdc_table[fd].write.handler_data), errcode, xerrno, retval);
 
     /* Clear out fd state */
     fdc_table[fd].write.handler = NULL;
     fdc_table[fd].write.handler_data = NULL;
-
-    /* Add it to the end of the list */
-    dlinkAddTail(cio, &(cio->h_node), &CommCallbackList);
-
-    /* and add it to the end of the fd list */
-    dlinkAddTail(cio, &(cio->fd_node), &(fdc_table[fd].CommCallbackList));
 }
 
-
-
-static void
-comm_call_io_callback(CommCallbackData *cio)
+void
+CommReadCallbackData::callCallback()
 {
-    switch(cio->type) {
-
-    case COMM_CB_READ:
-        cio->c.r_callback(cio->fd, cio->buf, cio->retval, cio->errcode, cio->xerrno,
-                          cio->callback_data);
-        break;
+    callback.handler(result.fd, buf, retval, result.errcode, result.xerrno, callback.data);
+}
 
-    case COMM_CB_WRITE:
-        cio->c.w_callback(cio->fd, cio->buf, cio->retval, cio->errcode, cio->xerrno,
-                          cio->callback_data);
-        break;
+void
+CommAcceptCallbackData::callCallback()
+{
+    callback.handler(result.fd, newfd, &details, result.errcode, result.xerrno, callback.data);
+}
 
-    case COMM_CB_ACCEPT:
-        cio->c.a_callback(cio->fd, cio->newfd, &cio->details, cio->errcode,
-                          cio->xerrno, cio->callback_data);
-        break;
+void
+CommWriteCallbackData::callCallback()
+{
+    callback.handler(result.fd, buf, retval, result.errcode, result.xerrno, callback.data);
+}
 
-    case COMM_CB_FILL:
-        cio->c.f_callback(cio->fd, cio->sb, cio->errcode,
-                          cio->xerrno, cio->callback_data);
-        break;
+void
+CommFillCallbackData::callCallback()
+{
+    callback.handler(result.fd, sb, result.errcode, result.xerrno, callback.data);
+}
 
-    default:
-        fatal("unknown comm io callback type!");
-        break;
-    };
+void
+CommCallbackData::fdClosing()
+{
+    result.errcode = COMM_ERR_CLOSING;
 }
 
+void
+CommCallbackData::callACallback()
+{
+    assert(fdc_table[result.fd].active == 1);
+    deRegisterSelf();
+    callCallback();
+}
 
 /*
  * call the IO callbacks
