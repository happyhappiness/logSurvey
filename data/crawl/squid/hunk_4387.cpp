     // update ICAP header
     icapBuf.Printf("%s=%d, ", section, (int) httpBuf.contentSize());
 
-    // pack HTTP head
-    packHead(httpBuf, head);
+    // begin cloning
+    HttpMsg *headClone = NULL;
+    
+    if (const HttpRequest* old_request = dynamic_cast<const HttpRequest*>(head)) {
+        HttpRequest* new_request = new HttpRequest;
+        urlParse(old_request->method, old_request->canonical,new_request);
+        new_request->http_ver = old_request->http_ver;
+        inheritVirginProperties(*new_request, *old_request);
+        headClone = new_request;
+    } 
+    else if (const HttpReply *old_reply = dynamic_cast<const HttpReply*>(head)) {
+        HttpReply* new_reply = new HttpReply;
+        new_reply->sline = old_reply->sline;
+        headClone = new_reply;
+    }
+    
+    Must(headClone);
+    
+    HttpHeaderPos pos = HttpHeaderInitPos;
+    HttpHeaderEntry* p_head_entry = NULL;
+    while (NULL != (p_head_entry = head->header.getEntry(&pos)) )
+        headClone->header.addEntry(p_head_entry->clone());
+
+    // end cloning
+        
+    // remove all hop-by-hop headers from the clone
+    headClone->header.removeHopByHopEntries();
+
+    // pack polished HTTP header
+    packHead(httpBuf, headClone);
+
+    delete headClone;
 }
 
 void ICAPModXact::packHead(MemBuf &httpBuf, const HttpMsg *head)
