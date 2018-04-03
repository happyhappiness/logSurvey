
    fwd = NULL; // refcounted

#if ICAP_CLIENT
    if (icap) {
        debug(11,5)("ServerStateData destroying icap=%p\n", icap);
        icap->ownerAbort();
        delete icap;
    }
#endif
}

#if ICAP_CLIENT
/*
 * Initiate an ICAP transaction.  Return true on success.
 * Caller will handle error condition by generating a Squid error message
 * or take other action.
 */
bool
ServerStateData::startIcap(ICAPServiceRep::Pointer service)
{
    debug(11,5)("ServerStateData::startIcap() called\n");
    if (!service) {
