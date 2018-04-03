 
     buf.append(ICAP::crlf, 2); // terminate Encapsulated line
 
-    if (shouldPreview()) {
+    if (shouldPreview(urlPath)) {
         buf.Printf("Preview: %d\r\n", (int)preview.ad());
         virginSendClaim.protectUpTo(preview.ad());
     }
