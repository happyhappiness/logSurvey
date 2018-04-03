         blen = base64_encode_update(&ctx, loginbuf, strlen(username), reinterpret_cast<const uint8_t*>(username));
         blen += base64_encode_update(&ctx, loginbuf+blen, strlen(request->peer_login +1), reinterpret_cast<const uint8_t*>(request->peer_login +1));
         blen += base64_encode_final(&ctx, loginbuf+blen);
-        httpHeaderPutStrf(hdr_out, header, "Basic %.*s", blen, loginbuf);
+        httpHeaderPutStrf(hdr_out, header, "Basic %.*s", (int)blen, loginbuf);
         return;
     }
 
