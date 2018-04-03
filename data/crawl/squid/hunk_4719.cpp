 #include "squid.h"
 #include "client_side_request.h"
 #include "ClientRequestContext.h"
-#include "MsgPipe.h"
 #include "MsgPipeData.h"
-#include "MsgPipeSource.h"
-#include "MsgPipeSink.h"
 #include "HttpRequest.h"
 #include "ICAPClientReqmodPrecache.h"
 #include "ICAPServiceRep.h"
 #include "ICAPClient.h"
 
 CBDATA_CLASS_INIT(ICAPClientReqmodPrecache);
 
-ICAPClientReqmodPrecache::ICAPClientReqmodPrecache(ICAPServiceRep::Pointer aService): service(aService), http(NULL), virgin(NULL), adapted(NULL)
+ICAPClientReqmodPrecache::ICAPClientReqmodPrecache(ICAPServiceRep::Pointer aService):
+    ICAPClientVector(aService, "ICAPClientReqmodPrecache"), http(NULL)
 {
-    debug(93,3)("ICAPClientReqmodPrecache constructed, this=%p\n", this);
-}
-
-ICAPClientReqmodPrecache::~ICAPClientReqmodPrecache()
-{
-    stop(notifyNone);
-    cbdataReferenceDone(http);
-    debug(93,3)("ICAPClientReqmodPrecache destructed, this=%p\n", this);
-
-    if (virgin != NULL)
-        freeVirgin();
-
-    if (adapted != NULL) {
-        /*
-         * adapted->sink is equal to this.  Remove the pointer since
-         * we are deleting this.
-         */
-
-        if (adapted->sink)
-            adapted->sink = NULL;
-
-        freeAdapted();
-    }
 }
 
 void ICAPClientReqmodPrecache::startReqMod(ClientHttpRequest *aHttp, HttpRequest *request)
 {
-    debug(93,3)("ICAPClientReqmodPrecache::startReqMod() called\n");
     http = cbdataReference(aHttp);
-
-    virgin = new MsgPipe("virgin"); // this is the place to create a refcount ptr
-    virgin->source = this;
-    virgin->data = new MsgPipeData;
-    virgin->data->cause = NULL;
-    virgin->data->setHeader(request);
-    virgin->data->body = new MemBuf;
-    virgin->data->body->init(ICAP::MsgPipeBufSizeMin, ICAP::MsgPipeBufSizeMax);
-
-    adapted = new MsgPipe("adapted");
-    adapted->sink = this;
-
-    ICAPInitXaction(service, virgin, adapted);
-
-    virgin->sendSourceStart(); // we may have virgin data to provide
-    adapted->sendSinkNeed();   // we want adapted response, eventially
-}
-
-void ICAPClientReqmodPrecache::sendMoreData(StoreIOBuffer buf)
-{
-    debug(93,3)("ICAPClientReqmodPrecache::sendMoreData() called\n");
-    //buf.dump();
-    /*
-     * The caller is responsible for not giving us more data
-     * than will fit in body MemBuf.  Caller should use
-     * potentialSpaceSize() to find out how much we can hold.
-     */
-    virgin->data->body->append(buf.data, buf.length);
-    virgin->sendSourceProgress();
+    startMod(http, NULL, request);
 }
 
-int
-ICAPClientReqmodPrecache::potentialSpaceSize()
-{
-    if (virgin == NULL)
-        return 0;
-
-    return (int) virgin->data->body->potentialSpaceSize();
-}
-
-// ClientHttpRequest says we have the entire HTTP message
-void ICAPClientReqmodPrecache::doneSending()
-{
-    debug(93,3)("ICAPClientReqmodPrecache::doneSending() called\n");
-
-    virgin->sendSourceFinish();
-}
-
-// ClientHttpRequest tells us to abort
-void ICAPClientReqmodPrecache::ownerAbort()
-{
-    debug(93,3)("ICAPClientReqmodPrecache::ownerAbort() called\n");
-    stop(notifyIcap);
-}
-
-// ICAP client needs more virgin response data
-void ICAPClientReqmodPrecache::noteSinkNeed(MsgPipe *p)
-{
-    debug(93,3)("ICAPClientReqmodPrecache::noteSinkNeed() called\n");
-
-    if (virgin->data->body->potentialSpaceSize())
-        http->icapSpaceAvailable();
-}
-
-// ICAP client aborting
-void ICAPClientReqmodPrecache::noteSinkAbort(MsgPipe *p)
-{
-    debug(93,3)("ICAPClientReqmodPrecache::noteSinkAbort() called\n");
-    stop(notifyOwner);
+void ICAPClientReqmodPrecache::tellSpaceAvailable() {
+    http->icapSpaceAvailable();
 }
 
 // ICAP client starts sending adapted response
