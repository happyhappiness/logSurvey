static PF commConnectFree;
static PF commHandleWrite;
static IPH commConnectDnsHandle;
static void requireOpenAndActive(int const fd);

static PF comm_accept_try;

class AcceptFD
{

public:
    AcceptFD() : count(0), finished_(false){}

    void doCallback(int fd, int newfd, comm_err_t errcode, int xerrno, ConnectionDetail *);
    void nullCallback();
    void beginAccepting() {count = 0; finished(false);}

    size_t acceptCount() const { return count;}

    bool finishedAccepting() const;
    CallBack<IOACB> callback;
    bool finished() const;
    void finished(bool);

private:
    static size_t const MAX_ACCEPT_PER_LOOP;
    size_t count;
    bool finished_;
};

size_t const AcceptFD::MAX_ACCEPT_PER_LOOP(10);

class fdc_t
{

public:
    void acceptOne(int fd);
    void beginAccepting();
    int acceptCount() const;
    fdc_t() : active(0), fd(-1), half_closed (false){CommCallbackList.head = NULL;CommCallbackList.tail = NULL; }

    fdc_t(int anFD) : active(0), fd(anFD), half_closed(false)
    {
        CommCallbackList.head = NULL;
        CommCallbackList.tail = NULL;
    }

    int active;
    int fd;
    dlink_list CommCallbackList;

    template<class P>
    bool findCallback(P predicate);

    class Accept
    {

    public:
        AcceptFD accept;
        ConnectionDetail connDetails;
    };

    Accept accept;

    bool half_closed;
};

typedef enum {
    COMM_CB_READ = 1,
    COMM_CB_DERIVED,
} comm_callback_t;

static int CommCallbackSeqnum = 1;

class CommCommonCallback
{

public:
    CommCommonCallback() : fd (-1), errcode (COMM_OK), xerrno(0), seqnum (CommCallbackSeqnum){}

    CommCommonCallback(int anFD, comm_err_t errcode, int anErrno) : fd (anFD), errcode (errcode), xerrno(anErrno), seqnum (CommCallbackSeqnum){}

    int fd;
    comm_err_t errcode;
    int xerrno;
    int seqnum;
};

class CommCallbackData
{

public:
    MEMPROXY_CLASS(CommCallbackData);
    CommCallbackData(CommCommonCallback const &);
    virtual ~CommCallbackData() {}

    virtual comm_callback_t getType() const { return COMM_CB_DERIVED; }

    void callACallback();
    void fdClosing();
    virtual void callCallback() = 0;
    void registerSelf();
    void deRegisterSelf();
    char *buf;
    StoreIOBuffer sb;

protected:
    CommCommonCallback result;
    friend void _comm_close(int fd, char const *file, int line);
    friend void comm_calliocallback(void);

private:
    dlink_node fd_node;
    dlink_node h_node;
};

MEMPROXY_CLASS_INLINE(CommCallbackData)

class CommAcceptCallbackData : public CommCallbackData
{

public:
    MEMPROXY_CLASS(CommAcceptCallbackData);
    CommAcceptCallbackData(int const anFd, CallBack<IOACB>, comm_err_t, int, int, ConnectionDetail const &);
    virtual void callCallback();

private:
    CallBack<IOACB> callback;
    int newfd;
    ConnectionDetail details;
};

MEMPROXY_CLASS_INLINE(CommAcceptCallbackData)

class CommFillCallbackData : public CommCallbackData
{

public:
    MEMPROXY_CLASS(CommFillCallbackData);
    CommFillCallbackData(int const anFd, CallBack<IOFCB> aCallback, comm_err_t, int);
    virtual void callCallback();

private:
    CallBack<IOFCB> callback;
};

MEMPROXY_CLASS_INLINE(CommFillCallbackData)

struct _fd_debug_t
{
    char const *close_file;
