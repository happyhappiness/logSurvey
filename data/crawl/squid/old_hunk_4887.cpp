        return 0;
    }

    if (fwdState->n_tries > 9)
        return 0;

    if (fwdState->origin_tries > 1)
        return 0;

    if (fwdState->request->flags.body_sent)
        return 0;

    assert(fs);

    fwdState->servers = fs->next;

    fwdServerFree(fs);

    if (fwdState->servers == NULL) {
        debug(17, 3) ("fwdReforward: No forward-servers left\n");
        return 0;
    }

    s = e->getReply()->sline.status;
    debug(17, 3) ("fwdReforward: status %d\n", (int) s);
    return fwdReforwardableStatus(s);
}

/* PUBLIC FUNCTIONS */

void
fwdServersFree(FwdServer ** FSVR)
{
    FwdServer *fs;

    while ((fs = *FSVR)) {
        *FSVR = fs->next;
        fwdServerFree(fs);
    }
}

void
fwdStart(int fd, StoreEntry * e, HttpRequest * r)
{
    FwdState *fwdState;
    int answer;
    ErrorState *err;
    /*
     * client_addr == no_addr indicates this is an "internal" request
     * from peer_digest.c, asn.c, netdb.c, etc and should always
     * be allowed.  yuck, I know.
     */

    if (r->client_addr.s_addr != no_addr.s_addr && r->protocol != PROTO_INTERNAL && r->protocol != PROTO_CACHEOBJ) {
        /*
         * Check if this host is allowed to fetch MISSES from us (miss_access)
         */
        ACLChecklist ch;
        ch.src_addr = r->client_addr;
        ch.my_addr = r->my_addr;
        ch.my_port = r->my_port;
        ch.request = requestLink(r);
        ch.accessList = cbdataReference(Config.accessList.miss);
        /* cbdataReferenceDone() happens in either fastCheck() or ~ACLCheckList */
        answer = ch.fastCheck();

        if (answer == 0) {
            err_type page_id;
            page_id = aclGetDenyInfoPage(&Config.denyInfoList, AclMatchedName);

            if (page_id == ERR_NONE)
                page_id = ERR_FORWARDING_DENIED;

            err = errorCon(page_id, HTTP_FORBIDDEN);

            err->request = requestLink(r);

            err->src_addr = r->client_addr;

            errorAppendEntry(e, err);

            return;
        }
    }

    debug(17, 3) ("fwdStart: '%s'\n", storeUrl(e));
    e->mem_obj->request = requestLink(r);
#if URL_CHECKSUM_DEBUG

    e->mem_obj->checkUrlChecksum();
#endif

    if (shutting_down) {
        /* more yuck */
        err = errorCon(ERR_SHUTTING_DOWN, HTTP_SERVICE_UNAVAILABLE);
        err->request = requestLink(r);
        errorAppendEntry(e, err);
        return;
    }

    switch (r->protocol) {
        /*
         * Note, don't create fwdState for these requests
         */

    case PROTO_INTERNAL:
        internalStart(r, e);
        return;

    case PROTO_CACHEOBJ:
        cachemgrStart(fd, r, e);
        return;

    case PROTO_URN:
        urnStart(r, e);
        return;

    default:
        break;
    }

    fwdState = cbdataAlloc(FwdState);
    fwdState->entry = e;
    fwdState->client_fd = fd;
    fwdState->server_fd = -1;
    fwdState->request = requestLink(r);
    fwdState->start = squid_curtime;
    storeLockObject(e);
    EBIT_SET(e->flags, ENTRY_FWD_HDR_WAIT);
    storeRegisterAbort(e, fwdAbort, fwdState);
    peerSelect(r, e, fwdStartComplete, fwdState);
}

void
fwdFail(FwdState * fwdState, ErrorState * errorState)
{
    debug(17, 3) ("fwdFail: %s \"%s\"\n\t%s\n",
                  err_type_str[errorState->type],
                  httpStatusString(errorState->httpStatus),
                  storeUrl(fwdState->entry));

    if (fwdState->err)
        errorStateFree(fwdState->err);

    fwdState->err = errorState;

    if (!errorState->request)
        errorState->request = requestLink(fwdState->request);
}

/*
 * Called when someone else calls StoreAbort() on this entry
 */
static void
fwdAbort(void *data)
{
    FwdState *fwdState = (FwdState *)data;
    debug(17, 2) ("fwdAbort: %s\n", storeUrl(fwdState->entry));
    fwdStateFree(fwdState);
}

/*
 * Accounts for closed persistent connections
 */
static void
fwdPeerClosed(int fd, void *data)
{
    peer *p = (peer *)data;
    p->stats.conn_open--;
}

/*
 * Frees fwdState without closing FD or generating an abort
 */
void
fwdUnregister(int fd, FwdState * fwdState)
{
    debug(17, 3) ("fwdUnregister: %s\n", storeUrl(fwdState->entry));
    assert(fd == fwdState->server_fd);
    assert(fd > -1);
    comm_remove_close_handler(fd, fwdServerClosed, fwdState);
    fwdState->server_fd = -1;
}

/*
 * server-side modules call fwdComplete() when they are done
 * downloading an object.  Then, we either 1) re-forward the
 * request somewhere else if needed, or 2) call storeComplete()
 * to finish it off
 */
void
fwdComplete(FwdState * fwdState)
{
    StoreEntry *e = fwdState->entry;
    assert(e->store_status == STORE_PENDING);
    debug(17, 3) ("fwdComplete: %s\n\tstatus %d\n", storeUrl(e),
                  e->getReply()->sline.status);
#if URL_CHECKSUM_DEBUG

    e->mem_obj->checkUrlChecksum();
#endif

    fwdLogReplyStatus(fwdState->n_tries, e->getReply()->sline.status);

    if (fwdReforward(fwdState)) {
        debug(17, 3) ("fwdComplete: re-forwarding %d %s\n",
                      e->getReply()->sline.status,
                      storeUrl(e));

        if (fwdState->server_fd > -1)
            fwdUnregister(fwdState->server_fd, fwdState);

        storeEntryReset(e);

        fwdStartComplete(fwdState->servers, fwdState);
    } else {
        debug(17, 3) ("fwdComplete: not re-forwarding status %d\n",
                      e->getReply()->sline.status);
        EBIT_CLR(e->flags, ENTRY_FWD_HDR_WAIT);
        e->complete();
        /*
         * If fwdState isn't associated with a server FD, it
         * won't get freed unless we do it here.
         */

        if (fwdState->server_fd < 0)
            fwdStateFree(fwdState);
    }
}

void
fwdPconnPush(int fd, const char *host, int port, const char *domain)
{
    fwdPconnPool->push(fd, host, port, domain);
}

void
fwdInit(void)
{
    cachemgrRegister("forward",
                     "Request Forwarding Statistics",
                     fwdStats, 0, 1);
#if WIP_FWD_LOG

    if (logfile)
