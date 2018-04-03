        return 0;
    }

    if (n_tries > 9)
        return 0;

    if (origin_tries > 1)
        return 0;

    if (request->flags.body_sent)
        return 0;

    assert(fs);

    servers = fs->next;

    fwdServerFree(fs);

    if (servers == NULL) {
        debug(17, 3) ("fwdReforward: No forward-servers left\n");
        return 0;
    }

    s = e->getReply()->sline.status;
    debug(17, 3) ("fwdReforward: status %d\n", (int) s);
    return reforwardableStatus(s);
}

static void
fwdStats(StoreEntry * s)
{
    int i;
    int j;
    storeAppendPrintf(s, "Status");

    for (j = 0; j <= MAX_FWD_STATS_IDX; j++) {
        storeAppendPrintf(s, "\ttry#%d", j + 1);
    }

    storeAppendPrintf(s, "\n");

    for (i = 0; i <= (int) HTTP_INVALID_HEADER; i++) {
        if (FwdReplyCodes[0][i] == 0)
            continue;

        storeAppendPrintf(s, "%3d", i);

        for (j = 0; j <= MAX_FWD_STATS_IDX; j++) {
            storeAppendPrintf(s, "\t%d", FwdReplyCodes[j][i]);
        }

        storeAppendPrintf(s, "\n");
    }
}


/**** STATIC MEMBER FUNCTIONS *************************************************/

bool
FwdState::reforwardableStatus(http_status s)
{
    switch (s) {

    case HTTP_BAD_GATEWAY:

    case HTTP_GATEWAY_TIMEOUT:
        return true;

    case HTTP_FORBIDDEN:

    case HTTP_INTERNAL_SERVER_ERROR:

    case HTTP_NOT_IMPLEMENTED:

    case HTTP_SERVICE_UNAVAILABLE:
        return Config.retry.onerror;

    default:
        return false;
    }

    /* NOTREACHED */
}

void
FwdState::pconnPush(int fd, const char *host, int port, const char *domain)
{
    fwdPconnPool->push(fd, host, port, domain);
}

void
FwdState::initModule()
{
    cachemgrRegister("forward",
                     "Request Forwarding Statistics",
                     fwdStats, 0, 1);
    memDataInit(MEM_FWD_SERVER, "FwdServer", sizeof(FwdServer), 0);

#if WIP_FWD_LOG

    if (logfile)
