 httpStart(FwdState *fwd)
 {
     debugs(11, 3, "httpStart: \"" << RequestMethodStr(fwd->request->method) << " " << fwd->entry->url() << "\"" );
-    HttpStateData *httpState = new HttpStateData(fwd);
+    AsyncJob::Start(new HttpStateData(fwd));
+}
 
-    if (!httpState->sendRequest()) {
+void
+HttpStateData::start()
+{
+    if (!sendRequest()) {
         debugs(11, 3, "httpStart: aborted");
-        delete httpState;
+        mustStop("HttpStateData::start failed");
         return;
     }
 
