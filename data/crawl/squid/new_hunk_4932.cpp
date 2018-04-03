        node = (clientStreamNode *)http->client_stream.tail->data;
        clientStreamRead(node, http, node->readBuffer);
    }

    /* ACCESS_ALLOWED continues here ... */
    safe_free(http->uri);

    http->uri = xstrdup(urlCanonical(http->request));

    http->doCallouts();
}

#if ICAP_CLIENT
void
ClientRequestContext::icapAccessCheck()
{
    ICAPAccessCheck *icap_access_check;

    if (icap_access_check = new ICAPAccessCheck(ICAP::methodReqmod, ICAP::pointPreCache, http->request, NULL, icapAclCheckDoneWrapper, this)) {
        icap_access_check->check();
        return;
    }

    http->doCallouts();
}

static void
icapAclCheckDoneWrapper(ICAPServiceRep::Pointer service, void *data)
{
    ClientRequestContext *calloutContext = (ClientRequestContext *)data;

    if (!calloutContext->httpStateIsValid())
        return;

    calloutContext->icapAclCheckDone(service);
}

void
ClientRequestContext::icapAclCheckDone(ICAPServiceRep::Pointer service)
{
    /*
     * No matching ICAP service in the config file
     */

    if (service == NULL) {
        http->doCallouts();
        return;
    }

    /*
     * Setup ICAP state and such.  If successful, just return.
     * We'll get back to doCallouts() after REQMOD is done.
     */
    if (0 == http->doIcap(service))
        return;

    /*
     * If doIcap() fails, then we have to either return an error
     * to the user, or keep going without ICAP.
     */
    fatal("Fix this case in ClientRequestContext::icapAclCheckDone()");

    http->doCallouts();
}

#endif

static void
clientRedirectAccessCheckDone(int answer, void *data)
{
