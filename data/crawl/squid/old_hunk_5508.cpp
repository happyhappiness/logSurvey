static int commRetryConnect(ConnectStateData * cs);
CBDATA_TYPE(ConnectStateData);

static MemPool *comm_write_pool = NULL;
static MemPool *conn_close_pool = NULL;

static void
CommWriteStateCallbackAndFree(int fd, comm_err_t code)
