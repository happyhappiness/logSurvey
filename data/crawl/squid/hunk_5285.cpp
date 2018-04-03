     bool half_closed;
 };
 
-
 typedef enum {
     COMM_CB_READ = 1,
-    COMM_CB_WRITE,
-    COMM_CB_ACCEPT,
-    COMM_CB_FILL
+    COMM_CB_DERIVED,
 } comm_callback_t;
 
-struct _CommCallbackData
+static int CommCallbackSeqnum = 1;
+
+class CommCommonCallback
 {
-    comm_callback_t type;
-    dlink_node fd_node;
-    dlink_node h_node;
+
+public:
+    CommCommonCallback() : fd (-1), errcode (COMM_OK), xerrno(0), seqnum (CommCallbackSeqnum){}
+
+    CommCommonCallback(int anFD, comm_err_t errcode, int anErrno) : fd (anFD), errcode (errcode), xerrno(anErrno), seqnum (CommCallbackSeqnum){}
+
     int fd;
-    int newfd;	/* for accept() */
-    char *buf;
-    int retval;
-    union {
-        IOCB *r_callback;
-        IOACB *a_callback;
-        IOFCB *f_callback;
-        IOWCB *w_callback;
-    } c;
-    void *callback_data;
     comm_err_t errcode;
     int xerrno;
     int seqnum;
-    ConnectionDetail details;
+};
+
+class CommCallbackData
+{
+
+public:
+    void *operator new(size_t);
+    void operator delete(void *);
+    virtual void deleteSelf() const;
+    CommCallbackData(CommCommonCallback const &);
+    virtual comm_callback_t getType() const { return COMM_CB_DERIVED; }
+
+    void callACallback();
+    void fdClosing();
+    virtual void callCallback() = 0;
+    void registerSelf();
+    void deRegisterSelf();
+    char *buf;
     StoreIOBuffer sb;
+
+protected:
+    CommCommonCallback result;
+    friend void _comm_close(int fd, char *file, int line);
+    friend void comm_calliocallback(void);
+
+private:
+    static MemPool *Pool;
+    dlink_node fd_node;
+    dlink_node h_node;
 };
 
-typedef struct _CommCallbackData CommCallbackData;
+class CommReadCallbackData : public CommCallbackData
+{
+
+public:
+    void *operator new(size_t);
+    void operator delete(void *);
+    void deleteSelf() const;
+    CommReadCallbackData(CommCommonCallback const &, CallBack<IOCB> aCallback, int);
+    virtual comm_callback_t getType() const { return COMM_CB_READ; }
+
+    virtual void callCallback();
+
+private:
+    static MemPool *Pool;
+    CallBack<IOCB> callback;
+    int retval;
+};
+
+class CommAcceptCallbackData : public CommCallbackData
+{
+
+public:
+    void *operator new(size_t);
+    void operator delete(void *);
+    void deleteSelf() const;
+    CommAcceptCallbackData(int const anFd, CallBack<IOACB>, comm_err_t, int, int, ConnectionDetail const &);
+    virtual void callCallback();
+
+private:
+    static MemPool *Pool;
+    CallBack<IOACB> callback;
+    int newfd;
+    ConnectionDetail details;
+};
+
+class CommFillCallbackData : public CommCallbackData
+{
+
+public:
+    void *operator new(size_t);
+    void operator delete(void *);
+    void deleteSelf() const;
+    CommFillCallbackData(int const anFd, CallBack<IOFCB> aCallback, comm_err_t, int);
+    virtual void callCallback();
+
+private:
+    static MemPool *Pool;
+    CallBack<IOFCB> callback;
+};
+
+class CommWriteCallbackData : public CommCallbackData
+{
+
+public:
+    void *operator new(size_t);
+    void operator delete(void *);
+    void deleteSelf() const;
+    CommWriteCallbackData(int const anFd, CallBack<IOWCB> aCallback, comm_err_t, int, int);
+    virtual void callCallback();
+
+private:
+    static MemPool *Pool;
+    CallBack<IOWCB> callback;
+    int retval;
+};
 
 struct _fd_debug_t
 {
