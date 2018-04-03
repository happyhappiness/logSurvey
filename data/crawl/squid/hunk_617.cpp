                 strFwd = request->client_addr.toStr(ntoabuf, MAX_IPSTRLEN);
         }
         if (strFwd.size() > 0)
-            hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.termedBuf());
+            hdr_out->putStr(Http::HdrType::X_FORWARDED_FOR, strFwd.termedBuf());
     }
     /** If set to DELETE - do not copy through. */
 
     /* append Host if not there already */
-    if (!hdr_out->has(HDR_HOST)) {
+    if (!hdr_out->has(Http::HdrType::HOST)) {
         if (request->peer_domain) {
-            hdr_out->putStr(HDR_HOST, request->peer_domain);
+            hdr_out->putStr(Http::HdrType::HOST, request->peer_domain);
         } else {
             SBuf authority = request->url.authority();
-            hdr_out->putStr(HDR_HOST, authority.c_str());
+            hdr_out->putStr(Http::HdrType::HOST, authority.c_str());
         }
     }
 
     /* append Authorization if known in URL, not in header and going direct */
-    if (!hdr_out->has(HDR_AUTHORIZATION)) {
+    if (!hdr_out->has(Http::HdrType::AUTHORIZATION)) {
         if (!request->flags.proxying && !request->url.userInfo().isEmpty()) {
             static uint8_t result[base64_encode_len(MAX_URL*2)]; // should be big enough for a single URI segment
             struct base64_encode_ctx ctx;
