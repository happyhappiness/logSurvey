 void
 ServerStateData::noteIcapAnswer(HttpMsg *msg)
 {
-    HttpReply *rep = dynamic_cast<HttpReply*>(msg);
-    HTTPMSGLOCK(rep);
     clearIcap(adaptedHeadSource); // we do not expect more messages
 
-    if (abortOnBadEntry("entry went bad while waiting for adapted headers")) {
-        HTTPMSGUNLOCK(rep); // hopefully still safe, even if "this" is deleted
+    if (abortOnBadEntry("entry went bad while waiting for adapted headers"))
         return;
-    }
 
+    HttpReply *rep = dynamic_cast<HttpReply*>(msg);
     assert(rep);
-    entry->replaceHttpReply(rep);
-    HTTPMSGUNLOCK(reply);
-
-    reply = rep; // already HTTPMSGLOCKed above
-
-    haveParsedReplyHeaders();
+    debugs(11,5, HERE << this << " setting adapted reply to " << rep);
+    setFinalReply(rep);
 
     assert(!adaptedBodySource);
-    if (reply->body_pipe != NULL) {
+    if (rep->body_pipe != NULL) {
         // subscribe to receive adapted body
-        adaptedBodySource = reply->body_pipe;
+        adaptedBodySource = rep->body_pipe;
         // assume that ICAP does not auto-consume on failures
         assert(adaptedBodySource->setConsumerIfNotLate(this));
     } else {
