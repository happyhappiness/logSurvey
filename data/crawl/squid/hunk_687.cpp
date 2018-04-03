     if (!hdr_out->has(HDR_HOST)) {
         if (request->peer_domain) {
             hdr_out->putStr(HDR_HOST, request->peer_domain);
-        } else if (request->port == urlDefaultPort(request->url.getScheme())) {
-            /* use port# only if not default */
-            hdr_out->putStr(HDR_HOST, request->GetHost());
         } else {
-            httpHeaderPutStrf(hdr_out, HDR_HOST, "%s:%d",
-                              request->GetHost(),
-                              (int) request->port);
+            SBuf authority = request->url.authority();
+            hdr_out->putStr(HDR_HOST, authority.c_str());
         }
     }
 
