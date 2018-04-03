ClientRequestContext::icapAclCheckDone(ICAPServiceRep::Pointer service)
{
    debugs(93,3,HERE << this << " icapAclCheckDone called");
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
    assert(http);

    if (0 == http->doIcap(service))
        return;

    /*
     * If doIcap() fails, then we have to either return an error
     * to the user, or keep going without ICAP.
     */
    fatal("Fix this case in ClientRequestContext::icapAclCheckDone()");

    // And when fixed, check whether the service is down in doIcap and
    // if it is, abort early, without creating ICAPClientReqmodPrecache.
    // See Server::startIcap() and its use.

    http->doCallouts();
}

#endif
