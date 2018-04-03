 void
 ConnStateData::noteBodyConsumerAborted(BodyPipe::Pointer )
 {
-    if (!closing())
-        startClosing("body consumer aborted");
+    // request reader may get stuck waiting for space if nobody consumes body
+    if (bodyPipe != NULL)
+        bodyPipe->enableAutoConsumption();
+
+    stopReceiving("virgin request body consumer aborted"); // closes ASAP
 }
 
 /** general lifetime handler for HTTP requests */
