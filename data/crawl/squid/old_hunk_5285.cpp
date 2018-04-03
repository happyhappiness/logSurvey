    bool half_closed;
};


typedef enum {
    COMM_CB_READ = 1,
    COMM_CB_WRITE,
    COMM_CB_ACCEPT,
    COMM_CB_FILL
} comm_callback_t;

struct _CommCallbackData
{
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
        IOWCB *w_callback;
    } c;
    void *callback_data;
    comm_err_t errcode;
    int xerrno;
    int seqnum;
    ConnectionDetail details;
    StoreIOBuffer sb;
};

typedef struct _CommCallbackData CommCallbackData;

struct _fd_debug_t
{
