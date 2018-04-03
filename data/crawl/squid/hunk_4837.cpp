     /* append Via */
     if (Config.onoff.via) {
         String strVia;
-        strVia = httpHeaderGetList(hdr_in, HDR_VIA);
+        strVia = hdr_in->getList(HDR_VIA);
         snprintf(bbuf, BBUF_SZ, "%d.%d %s",
                  orig_request->http_ver.major,
                  orig_request->http_ver.minor, ThisCache);
         strListAdd(&strVia, bbuf, ',');
-        httpHeaderPutStr(hdr_out, HDR_VIA, strVia.buf());
+        hdr_out->putStr(HDR_VIA, strVia.buf());
         strVia.clean();
     }
 
 #if ESI
     {
         /* Append Surrogate-Capabilities */
-        String strSurrogate (httpHeaderGetList(hdr_in, HDR_SURROGATE_CAPABILITY));
+        String strSurrogate (hdr_in->getList(HDR_SURROGATE_CAPABILITY));
         snprintf(bbuf, BBUF_SZ, "%s=\"Surrogate/1.0 ESI/1.0\"",
                  Config.Accel.surrogate_id);
         strListAdd(&strSurrogate, bbuf, ',');
-        httpHeaderPutStr(hdr_out, HDR_SURROGATE_CAPABILITY, strSurrogate.buf());
+        hdr_out->putStr(HDR_SURROGATE_CAPABILITY, strSurrogate.buf());
     }
 #endif
 
     /* append X-Forwarded-For */
-    strFwd = httpHeaderGetList(hdr_in, HDR_X_FORWARDED_FOR);
+    strFwd = hdr_in->getList(HDR_X_FORWARDED_FOR);
 
     if (opt_forwarded_for && orig_request->client_addr.s_addr != no_addr.s_addr)
         strListAdd(&strFwd, inet_ntoa(orig_request->client_addr), ',');
     else
         strListAdd(&strFwd, "unknown", ',');
 
-    httpHeaderPutStr(hdr_out, HDR_X_FORWARDED_FOR, strFwd.buf());
+    hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());
 
     strFwd.clean();
 
     /* append Host if not there already */
-    if (!httpHeaderHas(hdr_out, HDR_HOST)) {
+    if (!hdr_out->has(HDR_HOST)) {
         if (orig_request->peer_domain) {
-            httpHeaderPutStr(hdr_out, HDR_HOST, orig_request->peer_domain);
+            hdr_out->putStr(HDR_HOST, orig_request->peer_domain);
         } else if (orig_request->port == urlDefaultPort(orig_request->protocol)) {
             /* use port# only if not default */
-            httpHeaderPutStr(hdr_out, HDR_HOST, orig_request->host);
+            hdr_out->putStr(HDR_HOST, orig_request->host);
         } else {
             httpHeaderPutStrf(hdr_out, HDR_HOST, "%s:%d",
                               orig_request->host, (int) orig_request->port);
         }
     }
 
     /* append Authorization if known in URL, not in header and going direct */
-    if (!httpHeaderHas(hdr_out, HDR_AUTHORIZATION)) {
+    if (!hdr_out->has(HDR_AUTHORIZATION)) {
         if (!request->flags.proxying && *request->login) {
             httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s",
                               base64_encode(request->login));
