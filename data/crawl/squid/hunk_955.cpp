         static_cast<uint64_t>(lengthToSend(bodyData.range()));
     noteSentBodyBytes(length);
 
-    mb.Printf("%" PRIX64 "\r\n", length);
+    mb.appendf("%" PRIX64 "\r\n", length);
     mb.append(bodyData.data, length);
-    mb.Printf("\r\n");
+    mb.append("\r\n", 2);
 }
 
 /** put terminating boundary for multiparts */
 static void
 clientPackTermBound(String boundary, MemBuf * mb)
 {
-    mb->Printf("\r\n--" SQUIDSTRINGPH "--\r\n", SQUIDSTRINGPRINT(boundary));
+    mb->appendf("\r\n--" SQUIDSTRINGPH "--\r\n", SQUIDSTRINGPRINT(boundary));
     debugs(33, 6, "clientPackTermBound: buf offset: " << mb->size);
 }
 
