     // it is not clear what headers are required for control messages
     rep->header.removeHopByHopEntries();
     rep->header.putStr(Http::HdrType::CONNECTION, "keep-alive");
-    httpHdrMangleList(&rep->header, getCurrentContext()->http->request, ROR_REPLY);
+    httpHdrMangleList(&rep->header, pipeline.front()->http->request, ROR_REPLY);
 
     MemBuf *mb = rep->pack();
 
