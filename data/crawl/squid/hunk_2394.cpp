     }
 }
 
-// more adapted response body is available
 void
-ServerStateData::handleMoreAdaptedBodyAvailable()
+ServerStateData::resumeBodyStorage()
 {
-    const size_t contentSize = adaptedBodySource->buf().contentSize();
+    if (abortOnBadEntry("store entry aborted while kick producer callback"))
+        return;
 
-    debugs(11,5, HERE << "consuming " << contentSize << " bytes of adapted " <<
-           "response body at offset " << adaptedBodySource->consumedSize());
+    if(!adaptedBodySource)
+        return;
+
+    handleMoreAdaptedBodyAvailable();
+
+    if (adaptedBodySource != NULL && adaptedBodySource->exhausted())
+        endAdaptedBodyConsumption();
+}
 
+// more adapted response body is available
+void
+ServerStateData::handleMoreAdaptedBodyAvailable()
+{
     if (abortOnBadEntry("entry refuses adapted body"))
         return;
 
     assert(entry);
+
+    size_t contentSize = adaptedBodySource->buf().contentSize();
+    bool consumedPartially = false;
+
+    if (!contentSize)
+        return; // XXX: bytesWanted asserts on zero-size ranges
+
+    // XXX: entry->bytesWanted returns contentSize-1 if entry can accept data.
+    // We have to add 1 to avoid suspending forever.
+    const size_t bytesWanted = entry->bytesWanted(Range<size_t>(0, contentSize));
+    const size_t spaceAvailable = bytesWanted >  0 ? (bytesWanted + 1) : 0;
+
+    if (spaceAvailable < contentSize ) { 
+        // No or partial body data consuming
+        typedef NullaryMemFunT<ServerStateData> Dialer;
+        AsyncCall::Pointer call = asyncCall(93, 5, "ServerStateData::resumeBodyStorage",
+                                            Dialer(this, &ServerStateData::resumeBodyStorage));
+        entry->deferProducer(call);
+    }
+
+    // XXX: bytesWanted API does not allow us to write just one byte!
+    if (!spaceAvailable && contentSize > 1)  {
+        debugs(11, 5, HERE << "NOT storing " << contentSize << " bytes of adapted " <<
+               "response body at offset " << adaptedBodySource->consumedSize());
+        return;
+    }
+    
+    if (spaceAvailable < contentSize ) {
+        debugs(11, 5, HERE << "postponing storage of " <<
+               (contentSize - spaceAvailable) << " body bytes");
+        contentSize = spaceAvailable;
+        consumedPartially=true;
+    }
+    
+    debugs(11,5, HERE << "storing " << contentSize << " bytes of adapted " <<
+           "response body at offset " << adaptedBodySource->consumedSize());
+    
     BodyPipeCheckout bpc(*adaptedBodySource);
-    const StoreIOBuffer ioBuf(&bpc.buf, currentOffset);
-    currentOffset += bpc.buf.size;
+    const StoreIOBuffer ioBuf(&bpc.buf, currentOffset, contentSize);
+    currentOffset += ioBuf.length;
     entry->write(ioBuf);
     bpc.buf.consume(contentSize);
     bpc.checkIn();
