#include "MsgPipeSource.h"
#include "MsgPipeSink.h"
#include "HttpRequest.h"
#include "ICAPClientReqmodPrecache.h"
#include "ICAPServiceRep.h"
#include "ICAPClient.h"

#include "LeakFinder.h"

extern LeakFinder *MsgPipeLeaker;

CBDATA_CLASS_INIT(ICAPClientReqmodPrecache);

ICAPClientReqmodPrecache::ICAPClientReqmodPrecache(ICAPServiceRep::Pointer aService): service(aService), http(NULL), virgin(NULL), adapted(NULL)
{
    debug(93,3)("ICAPClientReqmodPrecache constructed, this=%p\n", this);
}

ICAPClientReqmodPrecache::~ICAPClientReqmodPrecache()
{
    stop(notifyNone);
    cbdataReferenceDone(http);
    debug(93,3)("ICAPClientReqmodPrecache destructed, this=%p\n", this);

    if (virgin != NULL)
        freeVirgin();
