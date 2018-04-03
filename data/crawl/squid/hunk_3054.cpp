         writeComplete(fd(), NULL, 0, COMM_OK);
 }
 
+/**
+ * Packs bodyData into mb using chunked encoding. Packs the last-chunk
+ * if bodyData is empty.
+ */
+void
+ClientSocketContext::packChunk(const StoreIOBuffer &bodyData, MemBuf &mb)
+{
+    const uint64_t length =
+        static_cast<uint64_t>(lengthToSend(bodyData.range()));
+    noteSentBodyBytes(length);
+
+    mb.Printf("%"PRIX64"\r\n", length);
+    mb.append(bodyData.data, length);
+    mb.Printf("\r\n");
+}
+
 /** put terminating boundary for multiparts */
 static void
 clientPackTermBound(String boundary, MemBuf * mb)
