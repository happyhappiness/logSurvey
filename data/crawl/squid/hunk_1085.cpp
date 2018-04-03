 
     blen = base64_encode_update(&ctx, loginbuf, strlen(request->peer_login), reinterpret_cast<const uint8_t*>(request->peer_login));
     blen += base64_encode_final(&ctx, loginbuf+blen);
-    httpHeaderPutStrf(hdr_out, header, "Basic %.*s", blen, loginbuf);
+    httpHeaderPutStrf(hdr_out, header, "Basic %.*s", (int)blen, loginbuf);
     return;
 }
 
