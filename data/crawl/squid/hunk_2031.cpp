         hdr->putStr(HDR_VIA, strVia.termedBuf());
     }
     /* Signal keep-alive or close explicitly */
-    hdr->putStr(HDR_CONNECTION, request->flags.proxy_keepalive ? "keep-alive" : "close");
+    hdr->putStr(HDR_CONNECTION, request->flags.proxyKeepalive ? "keep-alive" : "close");
 
 #if ADD_X_REQUEST_URI
     /*
