
CBDATA_CLASS_INIT(ICAPClientRespmodPrecache);

ICAPClientRespmodPrecache::ICAPClientRespmodPrecache(ICAPServiceRep::Pointer aService): service(aService), httpState(NULL), virgin(NULL), adapted(NULL)
{
    debug(93,5)("ICAPClientRespmodPrecache constructed, this=%p\n", this);
}

ICAPClientRespmodPrecache::~ICAPClientRespmodPrecache()
{
    stop(notifyNone);
    cbdataReferenceDone(httpState);
    debug(93,5)("ICAPClientRespmodPrecache destructed, this=%p\n", this);

    if (virgin != NULL)
