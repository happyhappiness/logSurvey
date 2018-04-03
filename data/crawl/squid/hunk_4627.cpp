 
 // received adapted response headers (body may follow)
 void
-ServerStateData::noteIcapHeadersAdapted()
+ServerStateData::noteIcapAnswer(HttpMsg *msg)
 {
-    // extract and lock reply before (adaptedHeadSource = NULL) can destroy it
-    HttpReply *rep = dynamic_cast<HttpReply*>(adaptedHeadSource->adapted.header);
+    HttpReply *rep = dynamic_cast<HttpReply*>(msg);
     HTTPMSGLOCK(rep);
-    adaptedHeadSource = NULL; // we do not expect any more messages from it
+    clearIcap(adaptedHeadSource); // we do not expect more messages
 
     if (abortOnBadEntry("entry went bad while waiting for adapted headers")) {
         HTTPMSGUNLOCK(rep); // hopefully still safe, even if "this" is deleted
