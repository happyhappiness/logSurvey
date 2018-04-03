
static PSC fwdPeerSelectionCompleteWrapper;
static CLCB fwdServerClosedWrapper;
#if USE_OPENSSL
static PF fwdNegotiateSSLWrapper;
#endif
static CNCB fwdConnectDoneWrapper;

static OBJH fwdStats;

#define MAX_FWD_STATS_IDX 9
static int FwdReplyCodes[MAX_FWD_STATS_IDX + 1][Http::scInvalidHeader + 1];

static PconnPool *fwdPconnPool = new PconnPool("server-side");
CBDATA_CLASS_INIT(FwdState);

void
FwdState::abort(void* d)
{
    FwdState* fwd = (FwdState*)d;
    Pointer tmp = fwd; // Grab a temporary pointer to keep the object alive during our scope.

    if (Comm::IsConnOpen(fwd->serverConnection())) {
        comm_remove_close_handler(fwd->serverConnection()->fd, fwdServerClosedWrapper, fwd);
        debugs(17, 3, HERE << "store entry aborted; closing " <<
               fwd->serverConnection());
        fwd->serverConnection()->close();
    } else {
        debugs(17, 7, HERE << "store entry aborted; no connection to close");
    }
    fwd->serverDestinations.clear();
    fwd->self = NULL;
}

/**** PUBLIC INTERFACE ********************************************************/

FwdState::FwdState(const Comm::ConnectionPointer &client, StoreEntry * e, HttpRequest * r, const AccessLogEntryPointer &alp):
