 void
 ServerStateData::handleAdaptedHeader(HttpMsg *msg)
 {
-    if (abortOnBadEntry("entry went bad while waiting for adapted headers"))
+    if (abortOnBadEntry("entry went bad while waiting for adapted headers")) {
+        // If the adapted response has a body, the ICAP side needs to know
+        // that nobody will consume that body. We will be destroyed upon
+        // return. Tell the ICAP side that it is on its own.
+        HttpReply *rep = dynamic_cast<HttpReply*>(msg);
+        assert(rep);
+        if (rep->body_pipe != NULL)
+            rep->body_pipe->expectNoConsumption();
+
         return;
+    }
 
     HttpReply *rep = dynamic_cast<HttpReply*>(msg);
     assert(rep);
