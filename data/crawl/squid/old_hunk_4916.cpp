#include "MsgPipeSink.h"
#include "HttpRequest.h"
#include "HttpReply.h"
#include "ICAPAnchor.h"
#include "ICAPClient.h"
#include "ICAPServiceRep.h"

#include "LeakFinder.h"

CBDATA_CLASS_INIT(ICAPAnchor);

extern LeakFinder *MsgPipeLeaker;

ICAPAnchor::ICAPAnchor(ICAPServiceRep::Pointer aService): service(aService), httpState(NULL), virgin(NULL), adapted(NULL)
{
    debug(93,5)("ICAPAnchor constructed, this=%p\n", this);
}

ICAPAnchor::~ICAPAnchor()
{
    stop(notifyNone);
    cbdataReferenceDone(httpState);
    debug(93,5)("ICAPAnchor destructed, this=%p\n", this);

    if (virgin != NULL)
        freeVirgin();
