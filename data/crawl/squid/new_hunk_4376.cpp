static PF commConnectFree;
static PF commHandleWrite;
static IPH commConnectDnsHandle;

static PF comm_accept_try;

class AcceptFD
{

public:
    AcceptFD(int aFd = -1): fd(aFd), theCallback(0), mayAcceptMore(false) {}

    void subscribe(AsyncCall::Pointer &call);
    void acceptNext();
    void notify(int newfd, comm_err_t, int xerrno, const ConnectionDetail &);

    int fd;

private:
    bool acceptOne();

    AsyncCall::Pointer theCallback;
    bool mayAcceptMore;
};

typedef enum {
    COMM_CB_READ = 1,
    COMM_CB_DERIVED,
} comm_callback_t;

struct _fd_debug_t
{
    char const *close_file;
