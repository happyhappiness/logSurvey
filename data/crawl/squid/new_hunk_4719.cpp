#include "squid.h"
#include "client_side_request.h"
#include "ClientRequestContext.h"
#include "MsgPipeData.h"
#include "HttpRequest.h"
#include "ICAPClientReqmodPrecache.h"
#include "ICAPServiceRep.h"
#include "ICAPClient.h"

CBDATA_CLASS_INIT(ICAPClientReqmodPrecache);

ICAPClientReqmodPrecache::ICAPClientReqmodPrecache(ICAPServiceRep::Pointer aService):
    ICAPClientVector(aService, "ICAPClientReqmodPrecache"), http(NULL)
{
}

void ICAPClientReqmodPrecache::startReqMod(ClientHttpRequest *aHttp, HttpRequest *request)
{
    http = cbdataReference(aHttp);
    startMod(http, NULL, request);
}

void ICAPClientReqmodPrecache::tellSpaceAvailable() {
    http->icapSpaceAvailable();
}

// ICAP client starts sending adapted response
