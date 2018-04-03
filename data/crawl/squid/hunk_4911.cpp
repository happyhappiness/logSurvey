 #include "MsgPipeSource.h"
 #include "MsgPipeSink.h"
 #include "HttpRequest.h"
-#include "ICAPClientSideHook.h"
+#include "ICAPClientReqmodPrecache.h"
 #include "ICAPServiceRep.h"
 #include "ICAPClient.h"
 
 #include "LeakFinder.h"
 
 extern LeakFinder *MsgPipeLeaker;
 
-CBDATA_CLASS_INIT(ICAPClientSideHook);
+CBDATA_CLASS_INIT(ICAPClientReqmodPrecache);
 
-ICAPClientSideHook::ICAPClientSideHook(ICAPServiceRep::Pointer aService): service(aService), http(NULL), virgin(NULL), adapted(NULL)
+ICAPClientReqmodPrecache::ICAPClientReqmodPrecache(ICAPServiceRep::Pointer aService): service(aService), http(NULL), virgin(NULL), adapted(NULL)
 {
-    debug(93,3)("ICAPClientSideHook constructed, this=%p\n", this);
+    debug(93,3)("ICAPClientReqmodPrecache constructed, this=%p\n", this);
 }
 
-ICAPClientSideHook::~ICAPClientSideHook()
+ICAPClientReqmodPrecache::~ICAPClientReqmodPrecache()
 {
     stop(notifyNone);
     cbdataReferenceDone(http);
-    debug(93,3)("ICAPClientSideHook destructed, this=%p\n", this);
+    debug(93,3)("ICAPClientReqmodPrecache destructed, this=%p\n", this);
 
     if (virgin != NULL)
         freeVirgin();
