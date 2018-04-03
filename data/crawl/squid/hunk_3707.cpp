     return false;
 }
 
-Adaptation::AccessCheck::AccessCheck(Method aMethod,
-                                     VectPoint aPoint,
-                                     HttpRequest *aReq,
-                                     HttpReply *aRep,
+Adaptation::AccessCheck::AccessCheck(const ServiceFilter &aFilter,
                                      AccessCheckCallback *aCallback,
-                                     void *aCallbackData): AsyncJob("AccessCheck"), done(FALSE)
+                                     void *aCallbackData):
+    AsyncJob("AccessCheck"), filter(aFilter),
+    callback(aCallback),
+    callback_data(cbdataReference(aCallbackData)),
+    acl_checklist(NULL)
 {
-    // TODO: assign these at creation time
-
-    method = aMethod;
-    point = aPoint;
-
-    req = HTTPMSGLOCK(aReq);
-    rep = aRep ? HTTPMSGLOCK(aRep) : NULL;
-
-    callback = aCallback;
-
-    callback_data = cbdataReference(aCallbackData);
-
-    acl_checklist = NULL;
-
 #if ICAP_CLIENT
-    Adaptation::Icap::History::Pointer h = req->icapHistory();
+    Adaptation::Icap::History::Pointer h = filter.request->icapHistory();
     if (h != NULL)
         h->start("ACL");
 #endif
 
-    debugs(93, 5, HERE << "AccessCheck constructed for " << methodStr(method) << " " << vectPointStr(point));
+    debugs(93, 5, HERE << "AccessCheck constructed for " <<
+        methodStr(filter.method) << " " << vectPointStr(filter.point));
 }
 
 Adaptation::AccessCheck::~AccessCheck()
 {
 #if ICAP_CLIENT
-    Adaptation::Icap::History::Pointer h = req->icapHistory();
+    Adaptation::Icap::History::Pointer h = filter.request->icapHistory();
     if (h != NULL)
         h->stop("ACL");
 #endif
-    HTTPMSGUNLOCK(req);
-    HTTPMSGUNLOCK(rep);
     if (callback_data)
         cbdataReferenceDone(callback_data);
 }
 
-/*
- * Walk the access rules list and find all classes that have at least
- * one service with matching method and vectoring point.
- */
+/// Walk the access rules list to find rules with applicable service groups
 void
 Adaptation::AccessCheck::check()
 {
     debugs(93, 4, HERE << "start checking");
 
     typedef AccessRules::iterator ARI;
     for (ARI i = AllRules().begin(); i != AllRules().end(); ++i) {
-
-        /*
-         * We only find the first matching service because we only need
-         * one matching service to justify ACL-checking a class.  We might
-         * use other services belonging to the class if the first service
-         * turns out to be unusable for some reason.
-         */
         AccessRule *r = *i;
-        ServicePointer service = findBestService(*r, false);
-        if (service != NULL) {
-            debugs(93, 5, HERE << "check: rule '" << r->id << "' has candidate service '" << service->cfg().key << "'");
+        if (isCandidate(*r)) {
+            debugs(93, 5, HERE << "check: rule '" << r->id << "' is a candidate");
             candidates += r->id;
         }
     }
