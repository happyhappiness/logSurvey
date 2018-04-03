ClientRequestContext::icapAclCheckDone(ICAPServiceRep::Pointer service)
{
    debugs(93,3,HERE << this << " icapAclCheckDone called");
    assert(http);

    if (http->startIcap(service))
        return;

    if (!service || service->bypass) {
        // handle ICAP start failure when no service was selected
        // or where the selected service was optional
        http->doCallouts();
        return;
    }

    // handle start failure for an essential ICAP service
    http->handleIcapFailure();
}

#endif
