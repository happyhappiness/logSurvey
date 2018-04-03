 
     outputBuffer.append(" [", 2);
 
-    outputBuffer.Printf("%" PRIu64 "<=%" PRIu64, theGetSize, thePutSize);
+    outputBuffer.appendf("%" PRIu64 "<=%" PRIu64, theGetSize, thePutSize);
     if (theBodySize >= 0)
-        outputBuffer.Printf("<=%" PRId64, theBodySize);
+        outputBuffer.appendf("<=%" PRId64, theBodySize);
     else
         outputBuffer.append("<=?", 3);
 
-    outputBuffer.Printf(" %d+%d", (int)theBuf.contentSize(), (int)theBuf.spaceSize());
+    outputBuffer.appendf(" %u+%u", theBuf.contentSize(), theBuf.spaceSize());
 
-    outputBuffer.Printf(" pipe%p", this);
+    outputBuffer.appendf(" pipe%p", this);
     if (theProducer.set())
-        outputBuffer.Printf(" prod%p", theProducer.get());
+        outputBuffer.appendf(" prod%p", theProducer.get());
     if (theConsumer.set())
-        outputBuffer.Printf(" cons%p", theConsumer.get());
+        outputBuffer.appendf(" cons%p", theConsumer.get());
 
     if (mustAutoConsume)
         outputBuffer.append(" A", 2);
