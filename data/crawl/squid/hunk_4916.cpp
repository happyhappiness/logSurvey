 #include "MsgPipeSink.h"
 #include "HttpRequest.h"
 #include "HttpReply.h"
-#include "ICAPAnchor.h"
+#include "ICAPClientRespmodPrecache.h"
 #include "ICAPClient.h"
 #include "ICAPServiceRep.h"
 
 #include "LeakFinder.h"
 
-CBDATA_CLASS_INIT(ICAPAnchor);
+CBDATA_CLASS_INIT(ICAPClientRespmodPrecache);
 
 extern LeakFinder *MsgPipeLeaker;
 
-ICAPAnchor::ICAPAnchor(ICAPServiceRep::Pointer aService): service(aService), httpState(NULL), virgin(NULL), adapted(NULL)
+ICAPClientRespmodPrecache::ICAPClientRespmodPrecache(ICAPServiceRep::Pointer aService): service(aService), httpState(NULL), virgin(NULL), adapted(NULL)
 {
-    debug(93,5)("ICAPAnchor constructed, this=%p\n", this);
+    debug(93,5)("ICAPClientRespmodPrecache constructed, this=%p\n", this);
 }
 
-ICAPAnchor::~ICAPAnchor()
+ICAPClientRespmodPrecache::~ICAPClientRespmodPrecache()
 {
     stop(notifyNone);
     cbdataReferenceDone(httpState);
-    debug(93,5)("ICAPAnchor destructed, this=%p\n", this);
+    debug(93,5)("ICAPClientRespmodPrecache destructed, this=%p\n", this);
 
     if (virgin != NULL)
         freeVirgin();
